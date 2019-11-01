#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main()
{
    struct song_node *table[27];
    printf("Testing print_list:\n");
    /* test insert_front */
    table[11] = insert_front(NULL, "Khalid", "Talk");
    table[0] = insert_front(NULL, "Avicii", "Waiting for Love");
    table[0] = insert_front(table[0], "Avicii", "Levels");
    print_list(table[0]);
    print_list(table[11]);

    /* test find_first */
    printf("find first song by Avicii: %s\n", find_first(table[0], "Avicii"));

    /* test find_node */
    printf("Testing find node:\n");
    printf("Looking for Avicii: Levels...\n");

    struct song_node * temp = find_node(table[0], "Avicii", "Levels");
    if(temp){
        printf("Node Found! %s: %s\n", temp->artist, temp->name);
    } else {
        printf("Node Not Found\n");
    }

    printf("Looking for Avicii: Wake Me Up...\n");
    temp = find_node(table[0], "Avicii", "Wake Me Up");
    if(temp){
        printf("Node Found! %s: %s\n", temp->artist, temp->name);
    }
    else {
        printf("Node Not Found\n");
    }
}
