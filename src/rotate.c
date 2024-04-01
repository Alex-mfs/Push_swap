#include "push_swap.h"

void	ft_ra(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return (0);
	first = *a;
	last = ft_stack_last(*a);
	*a = first->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return (0);
	first = *b;
	last = ft_stack_last(*b);
	*b = first->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int print)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && (*b) != cheapest->target)
		ft_rr(a, b, 1);
	set_index(*a);
	set_index(*b);
}