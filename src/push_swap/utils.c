/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:36 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 18:02:31 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

t_stack	*get_stack(int ac, char **av)
{
	int				i;
	t_stack			*a;
	int				j;

	i = 1;
	a = NULL;
	if (ac == 2)
		exit(EXIT_SUCCESS);
	while (i < ac)
	{
		j = ft_atoi(av[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}

long	ft_min(t_stack *a)
{
	long	min;

	min = a->nbr;
	while (a)
	{
		if (a->nbr < min)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

long	ft_max(t_stack *a)
{
	long	max;

	max = a->nbr;
	while (a)
	{
		if (a->nbr > max)
			max = a->nbr;
		a = a->next;
	}
	return (max);
}

t_stack	*ft_find_node(t_stack *stack, long nbr)
{
	while (stack)
	{
		if (stack->nbr == nbr)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
