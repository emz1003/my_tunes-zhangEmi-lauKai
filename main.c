#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main()
{
    struct song_node *table[27];
    printf("Testing print_list:\n");
    table[11] = insert_front(NULL, "Khalid", "Talk");
    table[1] = insert_front(NULL, "Avicii", "Levels");
    table[1] = insert_front(table[1], "Avicii", "Waiting for Love");
    print_list(table[1]);
    print_list(table[11]);
}
