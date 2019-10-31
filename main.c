#include <stdio.h>
#include <stdlib.h>
#include "my_tunes.h"

int main()
{
    struct song_node *table[27];
    // table =  malloc(27 *sizeof(struct song_node));
    printf("Testing print_list:\n");
    insert_front(table[11], "Khalid", "Talk");
    insert_front(table[1], "Avicii", "Levels");
    print_list(table);
}