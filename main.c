#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main()
{
    struct song_node *table[27];
    printf("Testing print_list:\n");
    table[11] = insert_front(NULL, "Khalid", "Talk");
    table[1] = insert_front(NULL, "Avicii", "Waiting for Love");
    table[1] = insert_front(table[1], "Avicii", "Levels");
    print_list(table[1]);
    print_list(table[11]);

    printf("Testing find node:\n");
    printf("Looking for Avicii: Levels...\n");
    if(find_node(table[1], "Avicii", "Levels")){
        printf("Node Found! %s: %s\n", find_node(table[1], "Avicii", "Levels")-> artist, find_node(table[1], "Avicii", "Levels")-> name);
    }
    else {
        printf("Node Not Found\n");
    }
    printf("Looking for Avicii: Wake Me Up...\n");
    if(find_node(table[1], "Avicii", "Wake Me Up")){
        printf("Node Found! %s: %s\n", find_node(table[1], "Avicii", "Wake Me Up")-> artist, find_node(table[1], "Avicii", "Wake Me Up")-> name);
    }
    else {
        printf("Node Not Found\n");
    }
}
