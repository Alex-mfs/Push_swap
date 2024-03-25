#include "push_swap.h"

void	ft_free(void *x)
{
	if (!x)
		return ;
	free(x);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_error_print(t_stack *a)
{
	write(2, "Error/n", 6);
	ft_stackclear(&a, ft_free);
	exit(EXIT_FAILURE);
}