int	ft_find_empty_cell(int **map, int **params, int dim);
int	ft_try_fill(int **map, int **params, int dim, int x, int y);
int	ft_is_observed_correctly(int **map, int **params, int dim);
int	ft_is_repeating(int **map, int dim, int x, int y);
void	ft_print_rect(int **map, int dim);

int	ft_find_empty_cell(int **map, int **params, int dim)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			if (map[i][j] == 0)
			{
				end = ft_try_fill(map, params, dim, i, j);
				return (end);
			}
			j++;
		}
		i++;
	}
	ft_print_rect(map, dim);
	if (!ft_is_observed_correctly(map, params, dim))
		return (0);
	return (1);
}

int	ft_try_fill(int **map, int **params, int dim, int x, int y)
{
	int	k;
	int	end;

	k = 1;
	while (k <= dim)
	{
		map[x][y] = k;
		if (!ft_is_repeating(map, dim, x, y))
		{
			end = ft_find_empty_cell(map, params, dim);
			if (end)
				return (1);
		}
		k++;
	}
	map[x][y] = 0;
	return (0);
}
