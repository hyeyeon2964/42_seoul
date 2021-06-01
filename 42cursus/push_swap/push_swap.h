#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


typedef struct s_node {
	int value;
	struct s_node *prev;
	struct s_node *next;
} t_node;

#endif

