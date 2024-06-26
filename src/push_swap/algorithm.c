/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:48:57 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 18:05:14 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	if ((*a)->nbr == ft_max(*a))
		ft_ra(a, 1);
	else if ((*a)->next->nbr == ft_max(*a))
		ft_rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a, 1);
}

void	ft_big_sort(t_stack **a)
{
	t_stack		*b;
	int			size_a;

	size_a = ft_stack_size(*a);
	b = NULL;
	if (size_a-- > 3 && !check_sort(*a))
		ft_pb(a, &b, 1);
	if (size_a-- > 3 && !check_sort(*a))
		ft_pb(a, &b, 1);
	if (size_a > 3 && !check_sort(*a))
		ft_move_to_b(a, &b);
	ft_sort_three(a);
	while (b)
	{
		init_stack_b(b, *a);
		ft_move_to_a(&b, a);
	}
	set_index(*a);
	ft_stackclear(&b, free);
}

void	ft_sort(t_stack **a)
{
	t_stack	*min;

	min = NULL;
	if (ft_stack_size(*a) == 2)
		ft_sa(a, 1);
	else if (ft_stack_size(*a) == 3)
		ft_sort_three(a);
	else if (ft_stack_size(*a) > 3)
		ft_big_sort(a);
	min = ft_find_node(*a, ft_min(*a));
	while ((*a) != min)
	{
		if (min->above_median)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}
