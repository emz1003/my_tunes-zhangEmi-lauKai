#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_node.h"

int main()
{
    srand(time(NULL));
    struct song_node *table[27];
    printf("Testing print_list:\n");
    /* test insert_front */

    table[10] = init_song_node("Khalid","Talk",NULL);
    table[10] = insert_front(table[10], init_song_node("Katy Perry", "Harleys in Hawaii", NULL));

    table[0] = init_song_node("Avicii", "Waiting for Love", NULL);
    table[0] = insert_front(table[0], init_song_node("Avicii", "Levels", NULL));
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
    print_list(table[10]);
    printf("Inserting Katy Perry: Never Really Over node:\n");\
    table[10] = insert_order(table[10], init_song_node("Katy Perry", "Never Really Over", NULL));
    print_list(table[10]);

    printf("Inserting Khalid: Walk into the Song node:\n");
    table[10] = insert_order(table[10], init_song_node("Khalid", "Walk into the Song", NULL));
    print_list(table[10]);

    printf("Inserting Katy Perry: Firework node:\n");
    table[10] = insert_order(table[10], init_song_node("Katy Perry", "Firework", NULL));
    print_list(table[10]);

    printf("Inserting Kelly Clarkson: Catch My Breath node:\n");
    table[10] = insert_order(table[10], init_song_node("Kelly Clarkson", "Catch My Breath", NULL));
    
    print_list(table[10]);
    printf("\n");

    /* test random element */
    struct song_node * arand = random_element(table[0]);
    printf("selecting random element from A: %s, %s\n", arand->artist, arand->name);
    struct song_node * krand = random_element(table[10]);
    printf("selecting random element from K: %s, %s\n", krand->artist, krand->name);
    printf("\n");

    /* test remove node */
    printf("removing Katy Perry: Firework node:\n");
    table[10] = remove_node(table[10], find_node(table[10], "Katy Perry", "Firework"));
    print_list(table[10]);

    printf("removing Khalid: Walk into the Song node:\n");
    table[10] = remove_node(table[10], find_node(table[10], "Khalid", "Walk into the Song"));
    print_list(table[10]);
}
