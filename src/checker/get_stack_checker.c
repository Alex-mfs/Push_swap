/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:48:48 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 18:06:20 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack_checker(int ac, char **av)
{
	int				i;
	t_stack			*a;
	int				j;

	i = 1;
	a = NULL;
	if (ac == 2 && !check_number(av[1]))
		ft_checker_error(a);
	while (i < ac)
	{
		j = ft_atoi(av[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}
