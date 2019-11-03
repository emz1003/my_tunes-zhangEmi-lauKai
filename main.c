#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

int main()
{
    srand(time(NULL));
    struct song_node *table[27];
    printf("Testing print_list:\n");
    /* test insert_front */
    table[10] = insert_front(NULL, "Khalid", "Talk");
    table[10] = insert_front(table[10], "Khalid", "Eastside");
    table[10] = insert_front(table[10], "Katy Perry", "Harleys in Hawaii");

    table[0] = insert_front(NULL, "Avicii", "Waiting for Love");
    table[0] = insert_front(table[0], "Avicii", "Levels");
    print_list(table[0]);
    print_list(table[10]);
    printf("\n");

    /* test find_first */
    printf("Find first song by Avicii: %s\n", find_first(table[0], "Avicii"));
    printf("\n");

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
    printf("\n");

    /* test insert_order */
    printf("Inserting Khalid: Walk into the song node:\n");
    struct song_node * temp2 = calloc(1, sizeof(struct song_node));
    strcpy(temp2->artist, "Katy Perry");
    strcpy(temp2->name, "Never Really Over");
    table[10] = insert_order(table[10], temp2);
    print_list(table[10]);
    printf("\n");

    /* test random element */
    struct song_node * arand = random_element(table[0]);
    printf("selecting random element from A: %s, %s\n", arand->artist, arand->name);
    struct song_node * krand = random_element(table[10]);
    printf("selecting random element from K: %s, %s\n", krand->artist, krand->name);
}
