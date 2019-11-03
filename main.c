#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_tunes.h"

int main()
{
    clear();
    srand(time(NULL));
    

    /* test insert front */

    printf("Testing insert front:\n");
    table[10] = init_song_node("khalid","talk",NULL);
    table[10] = insert_front(table[10], "katy perry", "harleys in hawaii");

    table[0] = init_song_node("avicii", "waiting for love", NULL);
    table[0] = insert_front(table[0],"avicii", "levels");

    /* test insert order */
    print_list(table[10]);
    printf("Inserting katy perry: never really over node:\n");\
    table[10] = insert_order(table[10], "katy perry", "never really over");
    print_list(table[10]);

    printf("Inserting khalid: walk into the song node:\n");
    table[10] = insert_order(table[10], "khalid", "walk into the song");
    print_list(table[10]);

    printf("Inserting katy perry: firework node:\n");
    table[10] = insert_order(table[10], "katy perry", "firework");
    print_list(table[10]);

    printf("Inserting kelly clarkson: catch my breath node:\n");
    table[10] = insert_order(table[10], "kelly clarkson", "catch my breath");
    print_list(table[10]);

    /* test print list */
    printf("Testing print_list:\n");
    print_list(table[0]);
    print_list(table[10]);
    printf("\n");

    /* test find node */
    printf("Testing find node:\n");
    printf("Looking for avicii: levels...\n");
    struct song_node * temp = find_node(table[0], "avicii", "levels");
    if(temp){
        printf("Node Found! %s: %s\n", temp->artist, temp->song);
    } else {
        printf("Node Not Found\n");
    }
    printf("Looking for avicii: wake me up...\n");
    temp = find_node(table[0], "avicii", "wake me up");
    if(temp){
        printf("Node Found! %s: %s\n", temp->artist, temp->song);
    }
    else {
        printf("Node Not Found\n");
    }
    printf("\n");

    /* test find first */
    printf("Testing find first:\n");
    printf("Find first song by avicii: %s\n", find_first(table[0], "avicii"));
    printf("\n");

    /* test random element */
    struct song_node * arand = random_element(table[0]);
    printf("selecting random element from A: %s, %s\n", arand->artist, arand->song);
    struct song_node * krand = random_element(table[10]);
    printf("selecting random element from K: %s, %s\n", krand->artist, krand->song);
    printf("\n");

    /* test remove node */
    printf("Removing katy perry: firework node:\n");
    table[10] = remove_node(table[10], find_node(table[10], "katy perry", "firework"));
    print_list(table[10]);

    printf("Removing khalid: walk into the song node:\n");
    table[10] = remove_node(table[10], find_node(table[10], "khalid", "walk into the song"));
    print_list(table[10]);
    printf("\n");

    /* test free list */
    print_list(table[0]);
    printf("Freeing table[0] (a):");
    table[0] = free_list(table[0]);
    print_list(table[0]);

    print_list(table[10]);
    printf("Freeing table[10] (k):");
    table[10] = free_list(table[10]);
    print_list(table[10]);
    printf("\n");

    /* test add song node */
    printf("Testing add_song_node:\n");
    printf("adding a new song_node with artist bazzi:");
    add_song_node("bazzi", "mine");
    printf("Printing table[1]:\n");
    print_list(table[1]);
    printf("\n");

    printf("Added a new bazzi song:\n");
    add_song_node("bazzi", "beautiful");
    print_list(table[1]);

    printf("adding post malone songs:");
    add_song_node("post malone", "sunflower");
    add_song_node("post malone", "circles");
    add_song_node("post malone", "better now");
    printf("\n");

    printf("Testing print_letter:\n");
    print_letter('p');

    /* testing find song */
    printf("Testing find song:\n");

    printf("looking for [post malone: sunflower]: \n");
    struct song_node *sunflower = find_song("post malone", "sunflower");
    if (sunflower)
        printf("song found! %s : %s\n", sunflower->artist, sunflower->song);
    else
        printf("song not found\n");
    
    printf("looking for [post malone: deja vu]: \n");
    struct song_node *dejavu = find_song("post malone", "deja vu");
    if (dejavu)
        printf("song found! %s : %s\n", dejavu->artist, dejavu->song);
    else
        printf("song not found\n");
    printf("\n");
    
    /* testing find artist */
    printf("Testing find artist:\n");

    printf("\n");
    /* testing print letter */
    printf("\n");
    /* testing print artist */
    printf("\n");
    /* testing print all */
    printf("\n");
    /* testing shuffle */
    printf("\n");
    /* testing delete song */
    printf("\n");
    /* testing clear */
    printf("\n");
}
