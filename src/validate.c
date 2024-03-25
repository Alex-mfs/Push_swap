#include "push_swap.h"

bool	check_sort(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->nbr < a->nbr)
				return (false);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (true);
}

bool	check_repeat(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->nbr == a->nbr)
				return	(false);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (true);
}

bool	check_number(char *nbr)
{
	long	n;
	int				i;

	n = ft_atoi(nbr);
	i = 0;
	if (nbr[0] == '\0')
		return (false);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]) && (nbr[i] != '-' && nbr[i] != '+'))
			return (false);
		if ((nbr[i] == '+' || nbr[i] == '-'))
		{
			if (i != 0 || !ft_isdigit(nbr[i + 1]))
				return (false);
		}
		i++;
	}
	return (true);
}

bool	validate_stack(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!check_number(av[i]))
			return (false);
		i++;
	}
	return (true);
}