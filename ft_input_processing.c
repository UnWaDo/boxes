void	ft_print(char *str);

int		ft_atoi(char *str);

int	ft_process_params(int argc, char **argv, int *params)
{
	int	i;
	int	p;

	i = 1;
	while (i < argc)
	{
		p = ft_atoi(argv[i]);
		if (p > 0 && p <= 4)
			params[i - 1] = p;
		else
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_ones_correct(int *params, int sector)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (i < 4 && amount < 2)
	{
		if (params[4 * sector + i] == 1)
		{
			amount++;
			if (params[(4 * sector + i + 4) % 16] == 1)
				return (0);
			if (params[(4 * (sector + 2) + (3 - i)) % 16] == 1)
				return (0);
		}
		i++;
	}
	if (amount >= 2)
		return (0);
	return (1);
}

int	ft_is_input_correct(int *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		if (!ft_is_ones_correct(params, i))
			return (0);
		while (j < 4)
		{
			if (params[4 * i + j] == 4
				&& params[(4 * (i + 2) + (3 - j)) % 16] != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_arguments_correct(int argc, char **argv, int *params)
{
	int	status;

	if (argc <= 16)
	{
		ft_print("Not enough arguments\n");
		return (0);
	}
	else if (argc > 17)
	{
		ft_print("Too many arguments\n");
		return (0);
	}
	status = ft_process_params(argc, argv, params);
	if (!status)
	{
		ft_print("Invalid arguments input\n");
		return (0);
	}
	status = ft_is_input_correct(params);
	if (!status)
	{
		ft_print("Impossible transposition\n");
		return (0);
	}
	return (1);
}
