void	ft_putchar(char c);

char	ft_character_for_map_print(int x, int y, int **map, int *params)
{
	if (((x == y) && (x == 0 || x == 5))
		|| ((x == 5 - y) && (x == 0 || x == 5)))
		return (' ');
	if (x == 0)
		return (params[y - 1] + '0');
	if (x == 5)
		return (params[4 - y + 8] + '0');
	if (y == 0)
		return (params[4 - x + 12] + '0');
	if (y == 5)
		return (params[x - 1 + 4] + '0');
	return (map[x - 1][y - 1] + '0');
}

void	ft_print_rect(int **map, int *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			ft_putchar(ft_character_for_map_print(i, j, map, params));
			j++;
		}
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
