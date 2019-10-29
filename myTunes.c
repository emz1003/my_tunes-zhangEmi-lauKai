#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "headers.h"

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
