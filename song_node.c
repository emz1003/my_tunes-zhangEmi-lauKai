#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_node.h"

void print_list(struct song_node *x)
{
    printf("[");
    while(x) {
        printf("%s: %s", x->artist, x->name);
        x = x->next;
        if(x) {
            printf(" | ");
        } else {
            break;
        }
    }
    printf("]\n");
}

struct song_node *insert_front(struct song_node *x, char *artist, char *name)
{
    struct song_node *temp = calloc(1, sizeof(struct song_node));
    strcpy(temp->artist, artist);
    strcpy(temp->name, name);
    temp->next = x;
    //printf("%s\n", temp-> artist);
    return temp;
}

char *find_first(struct song_node *x, char *artist) {
    if (!strcmp(x->artist, artist)) {
        return x->name;
    }

    if (strcmp(x->artist, artist) < 0) { // if artist > x->artist
        return find_first(x->next, artist);
    }

    return NULL; // artist not found

}

struct song_node *find_node(struct song_node *x, char *artist, char *name){
    struct song_node *temp = calloc(1, sizeof(struct song_node));
    while (x) {
      if (strcmp(x -> artist, artist)== 0 && strcmp(x -> name, name)== 0){
        temp = x;
        return temp;
      }
      x = x -> next;
    }
    return NULL;
}

struct song_node *insert_order(struct song_node *original, struct song_node *x){
    struct song_node *oldnext = calloc(1, sizeof(struct song_node));
    while(original){
      oldnext = original -> next;
      if(strcmp(x -> name, original -> name) > 0 && strcmp(x -> name, oldnext -> name) < 0){
        x -> next = oldnext;
        original -> next = x;
        return original;
      }
      original = original -> next;
    }
    return NULL;

}

struct song_node *random_element(struct song_node *node) {
    int len = 0;
    struct song_node * len_finder = node; 
    while(node) {
        node = node->next;
        len++;
    }
    srand(time(NULL));
    int rand = (float)rand()/(float)(RAND_MAX)) * len;
    int i;
    for (i = 0; i < rand; i++) {
        node = node->next;
    }
    return node;

}
// void remove_node(struct song_node *node);
// void free_list(struct song_node *nodes);
