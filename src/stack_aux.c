#include "push_swap.h"

ft_stack_size(t_stack	*stack)
{
	int		count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
