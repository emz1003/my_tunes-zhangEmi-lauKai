#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "headers.h"

void print_list(struct song_node *x) {
    if (x == NULL) {
      printf("[ ]\n");
      return;
    }
    printf("[ ");
    struct song_node *temp = x -> next;
    if (temp == NULL) printf("");
    else {
      printf("%s ", x->i);
      while(temp != NULL) {
          printf("%s ", temp->i);
          temp = temp -> next;
        }
      }
    printf("]\n");
}

struct song_node * insert_front(struct song_node *x, int y) {
    struct node *temp = malloc(sizeof(struct song_node));
    temp -> i = y;
    temp -> next = x;
    return temp;
}

int main() {
    struct song_node *table[27] = calloc (27, sizeof(struct song_node));
    printf("Testing print_list:\n");
    table[11] -> name = "Talk";
    table[11] -> artist = "Khalid";
    print_list(table);

    //printf("Adding #s 0-9 t list:\n");
    //for (int i = 0; i < 10; i++) {
    //  run = insert_front(run, i);
    //}
    //print_list(table);
  }
