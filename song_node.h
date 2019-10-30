#include <stdio.h>
#include <stdlib.h>

struct song_node
{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node *first_song(char *artist);
struct song_node *random_element();
void remove_node(struct song_node *node);
void free_list(struct song_node *nodes);
void print_list(struct song_node *x);
struct song_node *insert_front(struct song_node *x, char *art, char *na);