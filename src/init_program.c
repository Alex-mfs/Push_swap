int		check_args(int ac, char *av[])
{
	if (ac > 2)
	{
		if (ft_isdigit(ac, av) < 0 || invalid_number(ac, av) < 0
			|| check_repetition(ac, av) < 0)
			return (-1);
	}
}