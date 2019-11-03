#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_tunes.h"

void add_song_node(struct song_node *node){
    for (int i = 0; i < 27; i++) {
      if(table[i]){
        if(strncmp(node -> artist, table[i]->artist, 1) == 0) {
          insert_order (table[i], node);
        }
      }
    }
    char temp[2];
    strncpy ( temp, node->artist, 1 );
    int temp2 = temp[0] - 97;
    table[temp2] = node;
}
