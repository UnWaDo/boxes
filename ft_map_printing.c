void	ft_putchar(char c);

void	ft_print_rect(int **map, int dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim - 1)
		{
			ft_putchar(map[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar(map[i][j] + '0');
		ft_putchar('\n');
		i++;
	}
}

void	ft_put_to_all_copies(int **map, int to_put, int x, int y)
{
	map[x][y] = to_put;
	map[(x + 4)][3 - y] = to_put;
	map[8 + (3 - x)][3 - y] = to_put;
	map[12 + (3 - x)][y] = to_put;
}

void	ft_put_next_to_param(int **map, int to_put, int sector, int position)
{
	if (sector == 0)
		ft_put_to_all_copies(map, to_put, position, 0);
	else if (sector == 1)
		ft_put_to_all_copies(map, to_put, 3, position);
	else if (sector == 2)
		ft_put_to_all_copies(map, to_put, 3 - position, 3);
	else
		ft_put_to_all_copies(map, to_put, 0, 3 - position);
}
