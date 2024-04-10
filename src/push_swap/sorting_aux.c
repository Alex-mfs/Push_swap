/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:00 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 17:58:43 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bellow_media(t_stack *a, int media)
{
	int	result;

	result = 0;
	while (a)
	{
		if (a->nbr < media)
			result++;
		a = a->next;
	}
	return (result);
}

t_stack	*find_bellow(t_stack *a, int media)
{
	t_stack	*result;

	result = a;
	while (result->next)
	{
		if (result->index < media)
		{
			return (result);
		}
		result = result->next;
	}
	return (a);
}

/// @brief 
/// @param stack pilha, mais precisamente eh o topo da pilha
/// @param cheapest no que foi anteriormente class acim ou aba da med
/// @param k se se trata da pilha a ou b
void	pre_push(t_stack **stack, t_stack *cheapest, char k)
{
	while ((*stack) != cheapest)
	{
		if (k == 'a')
		{
			if (cheapest->above_median)
				ft_ra(stack, 1);
			else
				ft_rra(stack, 1);
		}
		else if (k == 'b')
		{
			if (cheapest->above_median)
				ft_rb(stack, 1);
			else
				ft_rrb(stack, 1);
		}
	}
}

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/// @brief atribui o target a cada numero da stack b para a stack a;
/// @param src b
/// @param dst a
void	set_target(t_stack *src, t_stack *dst)
{
	long	best_target;
	t_stack	*current_a;

	while (src)
	{
		best_target = LONG_MAX;
		current_a = dst;
		while (current_a)
		{
			if (current_a->nbr > src->nbr && current_a->nbr < best_target)
			{
				src->target = current_a;
				best_target = current_a->nbr;
			}
			current_a = current_a->next;
		}
		if (best_target == LONG_MAX)
		{
			best_target = ft_min(dst);
			src->target = ft_find_node(dst, best_target);
		}
		src = src->next;
	}
}
