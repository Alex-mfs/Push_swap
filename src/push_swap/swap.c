/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:27 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 17:51:24 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int print)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int print)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
