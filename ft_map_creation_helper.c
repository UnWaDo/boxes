void	ft_put_next_to_param(int **map, int dim, int side, int x)
{
	if (side == 0)
		map[0][x] = dim;
	else if (side == 1)
		map[dim - 1][x] = dim;
	else if (side == 2)
		map[x][0] = dim;
	else
		map[x][dim - 1] = dim;
}

void	ft_put_row_next_to_param(int **map, int dim, int side, int x)
{
	int	d;
	int	n;
	int	i;

	if (side % 2)
	{
		n = dim;
		d = -1;
	}
	else
	{
		n = 1;
		d = 1;
	}
	i = 0;
	while (i < dim)
	{
		if (side < 2)
			map[i][x] = n + i * d;
		else
			map[x][i] = n + i * d;
		i++;
	}
}
