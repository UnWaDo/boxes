int	ft_is_repeating_in_row(int **map, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (map[row][i] == 0)
		{
			i++;
			continue ;
		}
		j = i + 1;
		while (j < 4)
		{
			if (map[row][i] == map[row][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_repeating_in_column(int **map, int column)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (map[i][column] == 0)
		{
			i++;
			continue ;
		}
		j = i + 1;
		while (j < 4)
		{
			if (map[i][column] == map[j][column])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_repeating(int **map)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i < 4 && !res)
	{
		res = ft_is_repeating_in_row(map, i);
		i++;
	}
	i = 0;
	while (i < 4 && !res)
	{
		res = ft_is_repeating_in_column(map, i);
		i++;
	}
	return (res);
}
