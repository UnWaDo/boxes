int	ft_observe_level(int **map, int dim, int side, int x);

int	ft_is_observed_correctly(int **map, int **params, int dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < dim)
		{
			if (params[i][j] != ft_observe_level(map, dim, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_repeating(int **map, int dim, int x, int y)
{
	int	i;
	int	j;
	int	rep;

	rep = 0;
	i = 0;
	j = y;
	while (i < dim)
	{
		if (i != x && map[i][j] == map[x][y])
			return (1);
		i++;
	}
	i = x;
	j = 0;
	while (j < dim)
	{
		if (j != y && map[i][j] == map[x][y])
			return (1);
		j++;
	}
	return (0);
}
