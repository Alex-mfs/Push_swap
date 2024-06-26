/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:49:29 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 17:54:22 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_stackadd_front(a, tmp);
	if (print)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_stackadd_front(b, tmp);
	if (print)
		write(1, "pb\n", 3);
}
