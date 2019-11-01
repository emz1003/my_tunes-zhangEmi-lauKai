#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
// struct song_node *random_element();
// void remove_node(struct song_node *node);
// void free_list(struct song_node *nodes);
