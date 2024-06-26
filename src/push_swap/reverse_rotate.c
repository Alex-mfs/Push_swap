/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:49:39 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 18:03:22 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rra(t_stack **a, int print)
{
	t_stack	*tmp;
	t_stack	*penult;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_stack_last(*a);
	(*a)->next = tmp;
	while (tmp != *a)
	{
		penult = tmp;
		tmp = tmp->next;
	}
	penult->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int print)
{
	t_stack	*tmp;
	t_stack	*penult;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_stack_last(*b);
	(*b)->next = tmp;
	while (tmp != *b)
	{
		penult = tmp;
		tmp = tmp->next;
	}
	penult->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int print)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && (*b) != cheapest->target)
		ft_rrr(a, b, 1);
	set_index(*a);
	set_index(*b);
}
