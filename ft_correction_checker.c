int	ft_observe_level(int **map, int position)
{
	int	i;
	int	observe;
	int	height;

	height = 0;
	observe = 0;
	i = 0;
	while (i < 4)
	{
		if (map[position][i] > height)
		{
			observe++;
			height = map[position][i];
		}
		i++;
	}
	return (observe);
}

int	ft_is_observed_correctly(int **map, int *params)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (params[i] != ft_observe_level(map, i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_filled(int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
