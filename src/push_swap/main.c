/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:49:22 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 17:53:07 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;

	if (!validate_stack(ac, av))
		ft_error();
	if (ac < 2)
		exit(1);
	a = get_stack(ac, av);
	if (!check_repeat(a))
		ft_error_print(a);
	if (!check_sort(a))
		ft_sort(&a);
	ft_stackclear(&a, ft_free);
	return (0);
}
