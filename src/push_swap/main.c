#include "push_swap.h"

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
	{
		printf("%ld\n", a->nbr);
		ft_sort(&a);
	}
	ft_stackclear(&a, ft_free);
	return (0);
}
