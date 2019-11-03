#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "my_tunes.h"

void add_song_node(struct song_node *node){
  
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

    struct song_node *first = find_node(letter, artist, find_first(letter, artist));
    printf("[");
    while(!strcmp(first->artist, artist)) {
      printf("%s : %s", first->artist, first->song);
      if(!strcmp(first->next->artist, artist))
        printf(" | ");
    }
    return first->artist;
}

// void print_letter(char c); // kl 3
// void print_artist(char *artist); //kl 4
// void print_all(); // kl 5
void shuffle(){
  //print out a series of randomly chosen songs
  int i;
  //for()
} 
// void delete_song(char *artist, char *song); // kl 2
void clear(){
  int i;
  for(i = 0; i < 27; i++) {
    table[i] = free_list(table[i]);
  }
}
