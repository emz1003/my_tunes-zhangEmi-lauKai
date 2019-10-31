#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main()
{
    struct song_node *run = calloc (1, sizeof(struct song_node));
    // table =  malloc(27 *sizeof(struct song_node));
    printf("Testing print_list:\n");
    insert_front(run, "Khalid", "Talk");
    print_list(run);
    insert_front(run, "Avicii", "Levels");
    print_list(run);
}
