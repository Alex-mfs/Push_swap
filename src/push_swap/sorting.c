/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:08 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 17:57:08 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_until_media(t_stack **a, t_stack **b, int media)
{
	int				remaining;
	int				pb_needed;

	pb_needed = check_bellow_media(*a, media);
	remaining = ft_stack_size(*a);
	while (remaining > 3 && (pb_needed > 0) && !check_sort(*a))
	{
		pre_push((a), find_bellow(*a, media), 'a');
		if ((*a)->nbr < media)
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
	int		media;

	remaining = ft_stack_size(*a);
	while (remaining > 3 && !check_sort(*a))
	{
		remaining = ft_stack_size(*a);
		min = ft_min(*a);
		max = ft_max(*a);
		media = min + ((max - min) / 2);
		push_b_until_media(a, b, media);
	}
}

void	ft_move_to_a(t_stack	**src, t_stack	**dst)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*src);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(src, dst, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both(src, dst, cheapest);
	pre_push(src, cheapest, 'b');
	pre_push(dst, cheapest->target, 'a');
	ft_pa(dst, src, 1);
}

void	init_stack_b(t_stack *b, t_stack *a)
{
	set_index(a);
	set_index(b);
	set_target(b, a);
	calculate_cost(b, a);
	set_cheapest(b);
}
