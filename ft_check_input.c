int	ft_is_ones_and_dim_correct(int **params, int dim)
{
	int	i;
	int	one_amount;
	int	dim_amount;

	i = 0;
	amount = 0;
	dim_amount = 0;
	while (i < dim)
		j = 0;
		amount = 0;
		dim_amount = 0;
		while (j < dim && amount < 2 && dim_amount < 2)
		{
			if (params[i][j] == 1)
			{
				amount++;
				if (j != 3 && params[(i + 1) % 4][0] == 1)
					return (0);
				if (params[(4 * (sector + 2) + (3 - i)) % 16] == 1)
					return (0);
		}
		if (one_amount >= 2 || dim_amount >= 2)
			return (0);
		i++;
	}
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
