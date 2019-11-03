#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_node.h"

struct song_node *init_song_node(char *artist, char *song, struct song_node *next) {
    struct song_node *new = malloc(sizeof(struct song_node));
    new->artist = artist;
    new->song = song;
    new->next = next;
    return new;
}

struct song_node *insert_front(struct song_node *node, char *artist, char *song)
{
    struct song_node *x = init_song_node(artist, song, NULL);
    x->next = node;
    return x;
}

struct song_node *insert_order(struct song_node *original, char *artist, char *song){
    // if original is null or artist in front
    if(!original || strcmp(original->artist, artist) > 0){
        return insert_front(original, artist, song);
    }
    // same artist and song in front
    if(!strcmp(original->artist, artist) && strcmp(original->song, song) >= 0){
        return insert_front(original, artist, song);
    }
    struct song_node *node = init_song_node(artist, song, NULL);
    struct song_node *temp = original;
    struct song_node *next = temp->next;

    while(next){
        if (strcmp(next->artist, artist) > 0)
            break;

        if (!strcmp(next->artist, artist) && strcmp(next->song, song) >= 0)
            break;
        temp = next;
        next = temp->next;
    }

    temp->next = node;
    node->next = next;
    return original;
}

void print_list(struct song_node *x)
{
    printf("[");
    while(x) {
        printf("%s: %s", x->artist, x->song);
        x = x->next;
        if(x)
            printf(" | ");
        else
            break;
    }
    printf("]\n");
}

struct song_node *find_node(struct song_node *x, char *artist, char *song){
    while(x) {
      if (strcmp(x -> artist, artist) == 0 && strcmp(x -> song, song) == 0){
        return x;
      }
      x = x->next;
    }
    return NULL;
}

char * find_first(struct song_node *x, char *artist) {
    if(!x)
        return NULL;
    
    if (!strcmp(x->artist, artist)) {
        return x->song;
    }

    if (strcmp(x->artist, artist) < 0) { // if artist > x->artist
        return find_first(x->next, artist);
    }

    return NULL; // artist not found
}

struct song_node *random_element(struct song_node *node) {
    int len = 0;
    struct song_node * len_finder = node;
    while(len_finder) {
         len_finder = len_finder->next;
        len++;
    }
    int r = rand();
    int rand_index =((float)(r % 100) / 100) * (float)len;
    //printf("%d/%d\n", rand_index, len);
    int i;
    for (i = 0; i < rand_index; i++) {
        node = node->next;
    }
    return node;
}

struct song_node * remove_node(struct song_node *node, struct song_node *rm) {
    if(node == rm) {
        struct song_node *temp = node->next;
        free(rm);
        return temp;
    }

    struct song_node *temp = node;
    struct song_node *next = node->next;
    while(next) {
        if(next == rm) {
            temp->next = next->next;
            free(next);
            return node;
        }
        temp = next;
        next = temp->next;
    }
    return node;
}

struct song_node *free_list(struct song_node *nodes){
    while(nodes) {
        struct song_node *temp = nodes;
        nodes = nodes->next;
        free(temp);
    }
    return nodes;
}
