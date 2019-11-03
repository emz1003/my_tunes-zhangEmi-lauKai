#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_tunes.h"

void add_song_node(struct song_node *node){
    for (int i = 0; i < 27; i++) {
      if(table[i]){
        if(strncmp(node -> artist, table[i]->artist, 1) == 0) {
          insert_order (table[i], node);
        }
      }
    }
    char temp[2];
    strncpy ( temp, node->artist, 1 );
    int temp2 = temp[0] - 97;
    table[temp2] = node;
}

struct song_node *find_song(char *artist, char *song) {
  struct song_node * letter;
  if (isalpha(artist[0]))
    letter = table[(int) (artist[0] - 'a')];
  else
    letter = table[26]
  
  return find_node(letter, artist, song);
}
// char *find_artist(char *artist); // ez 2
// void print_letter(char c); // kl 3
// void print_artist(char *artist); //kl 4
// void print_all(); // kl 5
// void shuffle(); //print out a series of randomly chosen songs //ez 3
// void delete_song(char *artist, char *song); // kl 2
// void clear(); // ez 4
