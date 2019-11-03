#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

struct song_node * table[27];

void add_song_node(char *artist, char *song);
struct song_node *find_song(char *artist, char *song);
char *find_artist(char *artist);
void print_letter(char c);
void print_artist(char *artist);
void print_library();
void shuffle(int n); //print out a series of randomly chosen songs
void delete_song(char *artist, char *song);
void clear();
