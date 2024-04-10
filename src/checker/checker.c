/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:48:39 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/10 19:09:05 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_error(t_stack *a)
{
	write(2, "Error\n", 6);
	ft_stackclear(&a, ft_free);
	exit(EXIT_FAILURE);
}

bool	ft_check_reverserot(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 0);
	else if (line[2] == 'b')
		ft_rrb(b, 0);
	else if (line[2] == 'r')
		ft_rrr(a, b, 0);
	else
		return (false);
	return (true);
}

bool	checkcommand(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'p' && line [1] == 'a' && line[2] == '\0')
		ft_pa(a, b, 0);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\0')
		ft_pb(a, b, 0);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		ft_sa(a, 0);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
		ft_sb(b, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		ft_ss(a, b, 0);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		ft_ra(a, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		ft_rb(b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\0')
		ft_rr(a, b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\0')
		return (ft_check_reverserot(a, b, line));
	else
		return (false);
	return (true);
}

void	check_line(t_stack **a, t_stack **b)
{
	int		i;
	char	*line;
	char	c;

	i = 0;
	line = malloc(4);
	while (read(0, &c, 1))
	{
		if (c == '\n' || i >= 3)
		{
			line[i] = '\0';
			if (!checkcommand(a, b, line))
			{
				free(line);
				ft_stackclear(b, ft_free);
				ft_checker_error(*a);
			}
			free(line);
			line = malloc(4);
			i = 0;
		}
		else
			line[i++] = c;
	}
	free(line);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (!validate_stack(ac, av))
		ft_error();
	if (ac <= 1)
		exit(EXIT_FAILURE);
	a = get_stack_checker(ac, av);
	b = NULL;
	if (!check_repeat(a))
		ft_checker_error(a);
	check_line(&a, &b);
	if (check_sort(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stackclear(&a, ft_free);
	ft_stackclear(&b, ft_free);
	return (0);
}
