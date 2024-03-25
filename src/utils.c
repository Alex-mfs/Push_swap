#include "push_swap.h"

t_stack	*get_stack(int ac, char **av)
{
	int				i;
	t_stack	*a;
	int				j;

	i = 1;
	a = NULL;
	if (ac == 2)
		exit(EXIT_SUCCESS);//same as exit(0);
	while (i < ac)
	{
		j = ft_atoi(av[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
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