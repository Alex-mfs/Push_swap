/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:45 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 18:04:38 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_stackclear(t_stack **stack, void (*del)(void*))
{
	t_stack	*aux;

	if (!*stack || !del)
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		ft_free(*stack);
		*stack = aux;
	}
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min && stack->index == -1)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

void	index_stack(t_stack **stack_a)
{
	t_stack		*tmp;
	int			min;
	int			index;

	tmp = *stack_a;
	index = 1;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			min = find_min(tmp);
			if (tmp->nbr == min && tmp->index == -1)
			{
				tmp->index = index;
				index++;
				tmp = *stack_a;
			}
		}
		tmp = tmp->next;
	}
}
