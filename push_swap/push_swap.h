#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct  s_node
{
    int				value;
	int				index;
	int				push_cost;
	bool			bove_median;
	bool			cheapest;
	struct	s_node	*target_node;
	struct	s_node	*next;
	struct	s_node	*prev;
}				t_node;

//Handle errors

//Stack initiation
t_node *init_stack(void);

//Nodes initiation

//stack utils

//Commands

//Algorithms

#endif