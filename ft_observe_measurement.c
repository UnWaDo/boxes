int	ft_observe_row_positive(int **map, int dim, int row)
{
	int	i;
	int	observe;
	int	height;

	height = 0;
	observe = 0;
	i = 0;
	while (i < dim)
	{
		if (map[row][i] > height)
		{
			observe++;
			height = map[row][i];
		}
		i++;
	}
	return (observe);
}

int	ft_observe_row_negative(int **map, int dim, int row)
{
	int	i;
	int	observe;
	int	height;

	height = 0;
	observe = 0;
	i = dim - 1;
	while (i >= 0)
	{
		if (map[row][i] > height)
		{
			observe++;
			height = map[row][i];
		}
		i--;
	}
	return (observe);
}

int	ft_observe_col_positive(int **map, int dim, int col)
{
	int	i;
	int	observe;
	int	height;

	height = 0;
	observe = 0;
	i = 0;
	while (i < dim)
	{
		if (map[i][col] > height)
		{
			observe++;
			height = map[i][col];
		}
		i++;
	}
	return (observe);
}

int	ft_observe_col_negative(int **map, int dim, int col)
{
	int	i;
	int	observe;
	int	height;

	height = 0;
	observe = 0;
	i = dim - 1;
	while (i >= 0)
	{
		if (map[i][col] > height)
		{
			observe++;
			height = map[i][col];
		}
		i--;
	}
	return (observe);
}

int	ft_observe_level(int **map, int dim, int side, int x)
{
	int	observe;

	if (side == 0)
		observe = ft_observe_col_positive(map, dim, x);
	else if (side == 1)
		observe = ft_observe_col_negative(map, dim, x);
	else if (side == 2)
		observe = ft_observe_row_positive(map, dim, x);
	else
		observe = ft_observe_row_negative(map, dim, x);
	return (observe);
}
