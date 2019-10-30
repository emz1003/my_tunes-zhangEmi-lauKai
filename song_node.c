#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"
#include "my_tunes.h"

void print_list(struct song_node *x)
{
    if (x == NULL)
    {
        printf("[ ]\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < sizeof(x); i++)
    {
        struct song_node *temp = (x + i)->next;
        if (temp == NULL)
            printf("");
        else
        {
            printf("%s %s| ", (x + i)->artist, (x + i)->name);
            while (temp != NULL)
            {
                printf("%s %s| ", temp->artist, temp->name);
                temp = temp->next;
            }
        }
    }
    printf("]\n");
}

struct song_node *insert_front(struct song_node *x, char *art, char *na)
{
    struct song_node *temp = malloc(sizeof(struct song_node));
    strcpy(art, temp->artist);
    strcpy(na, temp->name);
    //temp -> artist = art;
    //temp -> name = na;
    temp->next = x;
    return temp;
}
