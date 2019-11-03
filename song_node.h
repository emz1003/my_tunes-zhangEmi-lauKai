#include <stdio.h>
#include <stdlib.h>

struct song_node
{
    char *artist;
    char *song;
    struct song_node *next;
};

struct song_node *init_song_node(char *artist, char *song, struct song_node *next);
struct song_node *insert_front(struct song_node *node, char *artist, char *song);
struct song_node *insert_order(struct song_node *original, char *artist, char *song);
void print_list(struct song_node *x);
struct song_node *find_node(struct song_node *x, char *artist, char *song);
char *find_first(struct song_node *x, char *artist);
struct song_node *random_element(struct song_node *x);
struct song_node *remove_node(struct song_node *node, struct song_node *rm);
struct song_node *free_list(struct song_node *nodes);
