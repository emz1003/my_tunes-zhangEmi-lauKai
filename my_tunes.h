#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

struct song_node * table[27];

void add_song_node(struct song_node *node); // kl 1
struct song_node *find_song(); // ez 1
char *find_artist(char *artist); // ez 2
void print_letter(char c); // kl 3
void print_artist(char *artist); //kl 4
void print_all(); // kl 5
void shuffle(); //print out a series of randomly chosen songs //ez 3
void delete_song(char *artist, char *song); // kl 2
void clear(); // ez 4
