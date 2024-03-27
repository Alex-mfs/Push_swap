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
bool	check_sort(t_stack *a);
bool	check_repeat(t_stack *a);
bool	check_number(char *nbr);
bool	validate_stack(int argc, char **argv);

//Stack 

//stack_aux
t_stack	*ft_stack_new(long content);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
int		ft_stack_size(t_stack *stack);

//stack utils
t_stack	*get_stack(int argc, char **argv);
long	ft_min(t_stack *a);
long	ft_max(t_stack *a);
void	ft_stackclear(t_stack **stack, void (*del)(void*));
t_stack	*ft_find_node(t_stack *stack, long nbr);

//Commands
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_pb(t_stack **b, t_stack **a, int print);
void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);
void	ft_ra(t_stack **a, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	ft_rra(t_stack **a, int print);
void	ft_rrb(t_stack **b, int print);
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

//sorting

//sorting_aux



//Algorithms
void	ft_sort(t_stack **a);
void	ft_big_sort(t_stack **a);
void	ft_sort_three(t_stack **a);

#endif