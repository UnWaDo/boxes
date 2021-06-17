void	ft_put_next_to_param(int **map, int to_put, int sector, int position);

int		ft_recursive_filling(int **map, int *params);

void	ft_put_to_all_copies(int **map, int to_put, int x, int y);

int		ft_is_repeating(int **map);

int	ft_locate_four(int **map, int *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (params[4 * i + j] == 1)
				ft_put_next_to_param(map, 4, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_try_fill (int **map, int *params, int x, int y)
{
	int	k;
	int	end;

	if (map[x][y] != 0)
		return (0);
	k = 1;
	while (k <= 4)
	{
		ft_put_to_all_copies(map, k, x, y);
		if (!ft_is_repeating(map))
		{
			end = ft_recursive_filling(map, params);
			if (end)
				return (1);
		}
		k++;
	}
	ft_put_to_all_copies(map, 0, x, y);
	return (0);
}
