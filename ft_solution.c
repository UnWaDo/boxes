typedef struct s_point {
	int	x;
	int	y;
}	t_point;

int		ft_find_empty_cell(int **map, int **params, int dim);
int		ft_try_fill(int **map, int **params, int dim, t_point p);
int		ft_is_observed_correctly(int **map, int **params, int dim);
int		ft_is_repeating(int **map, int dim, int x, int y);
void	ft_print_rect(int **map, int dim);
int		ft_observe_level(int **map, int dim, int side, int x);

t_point	ft_find_empty_cell_in_row(int **map, int dim, int row)
{
	int		i;
	t_point	p;

	p.x = -1;
	p.y = -1;
	i = 0;
	while (i < dim)
	{
		if (map[row][i] == 0)
		{
			p.x = row;
			p.y = i;
			return (p);
		}
		i++;
	}
	return (p);
}

int	ft_find_empty_cell(int **map, int **params, int dim)
{
	int		i;
	int		end;
	t_point	p;

	i = 0;
	while (i < dim)
	{
		p = ft_find_empty_cell_in_row(map, dim, i);
		if (p.x != -1)
		{
			end = ft_try_fill(map, params, dim, p);
			return (end);
		}
		if (ft_observe_level(map, dim, 2, i) != params[2][i])
			return (0);
		if (ft_observe_level(map, dim, 3, i) != params[3][i])
			return (0);
		i++;
	}
	if (!ft_is_observed_correctly(map, params, dim))
		return (0);
	return (1);
}

int	ft_try_fill(int **map, int **params, int dim, t_point p)
{
	int	k;
	int	end;

	k = 1;
	while (k <= dim)
	{
		map[p.x][p.y] = k;
		if (!ft_is_repeating(map, dim, p.x, p.y))
		{
			end = ft_find_empty_cell(map, params, dim);
			if (end)
				return (1);
		}
		k++;
	}
	map[p.x][p.y] = 0;
	return (0);
}
