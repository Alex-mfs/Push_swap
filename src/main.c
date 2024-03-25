#include "push_swap.h"

int		arg_arr(int ac, char *av[])
{
	int				i;
	long int			current;
	long int			next;

	i = 1;
	if (ac > 2)
	{
		if (check_args(ac, av) < 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;

	if (!validate_stack(ac, av))
		ft_error();
	if (ac < 2)
		exit(1); // same as exit(EXIT_FAILURE)
	a = get_stack(ac, av);
	if (!check_repeat(a))
		ft_error_print(a);
	if (!check_sort(a))
		ft_sort(&a);
	return (0);
}
