#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "unistd.h"
#include "stdlib.h"

typedef struct Node {
	int value;
	struct Node* next;
} Node;

typedef struct Head {
	Node* top;
	int size;
} Head;

#endif

