#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_tunes.h"

void add_song_node(char *artist, char *song){
    struct song_node *node = init_song_node(artist, song, NULL);
    for (int i = 0; i < 27; i++) {
      if(isalpha(artist[0])){
        char c = i + 'a';
        char *p = &c;
        if(strncmp(artist, p, 1) == 0)
          table[i] = insert_order(table[i], artist, song);
      } else if (i == 26){
        table[26] = insert_order(table[26], artist, song);
      }
    }
}

struct song_node *find_song(char *artist, char *song) {
  struct song_node * letter;
  if (isalpha(artist[0]))
    letter = table[(int) (artist[0] - 'a')];
  else
    letter = table[26];
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

void print_letter(char c) {
    struct song_node *letter;
    if (isalpha(c))
      letter = table[(int) (c - 'a')];
    else
      letter = table[26];
    print_list(letter);
}

void print_artist(char *artist) {
    struct song_node *run;
    if (isalpha(artist[0]))
      run = table[(int) (artist[0] - 'a')];
    else
      run = table[26];
    while(run) {
      if (strcmp(run -> artist, artist) == 0) {
        printf("[ %s : %s ]\n", run -> artist, run -> song);
      }
      run = run -> next;
    }
}

void print_library(){
    for (int i = 0; i < 27; i++) {
      if(table[i] && i != 26){
        printf("Printing the %c list:\n", 'a' + i);
        print_list(table[i]);
      } else if (i == 26) {
        printf("Printing the misc list:\n");
        print_list(table[26]);
      }
    }
}

void shuffle(int n){
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
