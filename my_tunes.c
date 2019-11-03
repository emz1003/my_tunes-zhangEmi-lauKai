#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_tunes.h"

void add_song_node(char *artist, char *song){ // account for non alpha cases
    struct song_node *node = init_song_node(artist, song, NULL);
    for (int i = 0; i < 27; i++) {
      char c = i + 'a';
      char *p = &c;
      if(strncmp(artist, p, 1) == 0)
        table[i] = insert_order(table[i], artist, song);
    }
}

struct song_node *find_song(char *artist, char *song) {
  struct song_node * letter;
  if (isalpha(artist[0]))
    letter = table[(int) (artist[0] - 'a')];
  else
    letter = table[26];
  print_list(table[15]);
  return find_node(letter, artist, song);
}

char *find_artist(char *artist) {
    struct song_node *letter;
    if (isalpha((int) artist[0]))
      letter = table[(int) (artist[0] - 'a')];
    else
      letter = table[26];
    printf("table set\n");

    char *result = find_first(letter,artist);
    if(result)
      return artist;
    return NULL;
}

void print_letter(char c) { // account for non alpha cases
    int temp = c - 97;
    print_list(table[temp]);
}

void print_artist(char *artist) {
    char temp[2];
    strncpy (temp, artist, 1);
    int index = temp[0]-97;
    struct song_node *run = table[index];
    while(run) {
      if (strcmp(run -> artist, artist) == 0) {
        printf("[ %s : %s ]\n", run -> artist, run -> song);
      }
      run = run -> next;
    }
}

void print_library(){
    for (int i = 0; i < 27; i++) {
      if(table[i]){
        char temp[1];
        strncpy(temp, table[i]-> artist, 1);
        printf("Printing the %s list:\n", temp);
        print_list(table[i]);
      }
    }
}

void shuffle(int n){ // account for void cases
  //print out a series of randomly chosen songs
  int i;
  printf("[");
  for(i = 0; i < n; i++) {
    int randint = rand() % 27;
    while (!table[randint]) {
      randint = rand() % 27;
    }
    struct song_node *r = random_element(table[randint]);
    printf("%s : %s", r->artist, r->song);
    if (i != n - 1)
      printf(" | ");
  }
  printf("]\n");
}

void delete_song(char *artist, char *song){
  struct song_node * letter;
  if (isalpha(artist[0]))
    letter = table[(int) (artist[0] - 'a')];
  else
    letter = table[26];
  remove_node(letter, find_song(artist, song));
}

void clear(){
  int i;
  for(i = 0; i < 27; i++) {
    table[i] = free_list(table[i]);
  }
}
