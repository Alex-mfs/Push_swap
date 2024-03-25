#include "push_swap.h"

int	ft_ra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return (0);
	tmp = *a;
	*a = ft_stack_last(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}