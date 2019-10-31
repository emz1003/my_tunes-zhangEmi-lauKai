#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

void print_list(struct song_node *x) {
  void print_list(struct node * n) {
  printf("[");
  while(n) {
      printf("%i", n->i);
      n = n->next;
      if(n) {
          printf(", ");
      } else {
          break;
      }
  }
  printf("]\n");
}
}

struct song_node *insert_front(struct song_node *x, char *art, char *na)
{
    struct song_node *temp = malloc(sizeof(struct song_node));
    strcpy(temp -> artist, art);
    strcpy(temp -> name, na);
    //temp -> artist = art;
    //temp -> name = na;
    temp->next = x;
    //printf("%s\n", temp-> artist);
    return temp;
}
