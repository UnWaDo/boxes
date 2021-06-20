typedef struct s_point {
	int	x;
	int	y;
}	t_point;

int		ft_find_empty_cell(int **map, int **params, int dim);
int		ft_try_fill(int **map, int **params, int dim, t_point p);
int		ft_is_observed_correctly(int **map, int **params, int dim);
int		ft_is_repeating(int **map, int dim, int x, int y);
void	ft_print_rect(int **map, int dim);

int	ft_find_empty_cell(int **map, int **params, int dim)
{
	int		i;
	int		j;
	int		end;
	t_point	p;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			if (map[i][j] == 0)
			{
				p.x = i;
				p.y = j;
				end = ft_try_fill(map, params, dim, p);
				return (end);
			}
			j++;
		}
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
