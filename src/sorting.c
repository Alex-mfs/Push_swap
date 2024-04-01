#include "push_swap.h"

void	push_b_until_target(t_stack **a, t_stack **b, int target)
{
	int		remaining;
	int 	pb_needed;

	pb_needed = check_bellow_target(*a, target);
	remaining = ft_stack_size(*a);
	while (remaining > 3 && (pb_needed > 0) && !check_sort(*a))
	{
		set_index(*a);
		pre_push((a), find_bellow(*a, target), 'a');
		if ((*a)->nbr < target)
		{
			ft_pb(a, b, 1);
			remaining--;
			pb_needed--;
		}
		else
			ft_ra(a, 1);
	}
}


void	ft_move_to_b(t_stack **a, t_stack **b)
{
	int		remaining;
	long	min;
	long	max;
	int		target;

	remaining = ft_stack_size(*a);
	while (remaining > 3 && !check_sort(*a))
	{
		remaining = ft_stack_size(*a);
		min = ft_min(*a);
		max = ft_max(*a);
		target = min + ((max - min) / 2);
		push_b_until_target(a, b, target);
	}
}


void	init_stack_b(t_stack *b, t_stack *a)
{
	set_index(a);
	set_index(b);
	set_target(b, a);
	calculate_cost(b, a);
	set_min_cost(b);
}