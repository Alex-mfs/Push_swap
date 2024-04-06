#include "push_swap.h"

void	calculate_cost(t_stack	*src, t_stack *dst)
{
	int	size_src;
	int	size_dst;

	size_src = ft_stack_size(src);
	size_dst = ft_stack_size(dst);
	while (src)
	{
		update_cost(src, size_src, size_dst);
		src = src->next;
	}
}

t_stack	*find_cheapest(t_stack	*stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		else
			stack->cheapest = false;
		stack = stack->next;
	}
	return (NULL);
}

/// @brief para ver se vale a pena fazer operacoes ao mesmo tempo nas listas;
/// @param src eh a stack a ou b;
/// @param size_src o tamanho dessa stack
/// @param size_dst o tamanho da stack destino
void	update_cost(t_stack	*src, int size_src, int size_dst)
{
	src->push_cost = src->index;
	if (!src->above_median)
		src->push_cost = size_src - src->index;
	if (src->target->above_median)
	{
		if (!src->above_median)
			src->push_cost = src->target->index + size_src - src->index;
		else if (src->push_cost < src->target->index)
			src->push_cost = src->target->index;
	}
	else
	{
		if (src->above_median)
			src->push_cost += size_dst - src->target->index;
		else if (src->push_cost < (size_dst - src->target->index))
			src->push_cost = size_dst - src->target->index;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*real_cheapest;
	long	cheapest_value;

	if (!stack)
		return;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			real_cheapest = stack;
		}
		else
			stack->cheapest = false;
		stack = stack->next;
	}
	real_cheapest->cheapest = true;
}