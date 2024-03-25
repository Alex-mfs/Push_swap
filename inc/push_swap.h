#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#define bool _Bool

typedef struct  s_stack
{
    long				nbr;
	int				index; // number position
	int				push_cost; // how maany commands in total
	bool			above_median; // used to calculate the push cost
	bool			cheapest; // the node that is the cheapest to do commands
	struct	s_stack	*target_node; // the target node of a node in the opposite stack
	struct	s_stack	*next; // pointer to the next node
}				t_stack;

//Handle errors

//Stack initiation

//Nodes initiation

//stack utils

//Commands

//Algorithms

#endif