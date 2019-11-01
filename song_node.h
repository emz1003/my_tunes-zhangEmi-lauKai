#include <stdio.h>
#include <stdlib.h>

struct song_node
{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node *insert_front(struct song_node *x, char *artist, char *name);
struct song_node *insert_order(struct song_node *x, char *artist, char *name);
void print_list(struct song_node *x);
struct song_node *find_song(struct song_node *x, char *art, char *na);
char *find_first(struct song_node *x, char *artist);
struct song_node *random_element(struct song_node *x);
void remove_node(struct song_node *node, struct song_node *rm);
void free_list(struct song_node *nodes);
