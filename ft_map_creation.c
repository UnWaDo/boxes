#include "ft_memory.h"

void	ft_put_next_to_param(int **map, int dim, int side, int x);
void	ft_put_row_next_to_param(int **map, int dim, int side, int x);

int	**ft_create_map(int dim)
{
	int	i;
	int	**map;

	if (dim <= 1)
		return (0);
	map = malloc(sizeof(*map) * dim);
	if (!map)
		return (0);
	i = 0;
	while (i < dim)
	{
		map[i] = malloc(sizeof(**map) * dim);
		if (!map[i])
		{
			ft_free((void **) map, i - 1);
			return (0);
		}
		i++;
	}
	return (map);
}

void	ft_fill_zeros(int **map, int dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_locate_predefined(int **map, int **params, int dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < dim)
		{
			if (params[i][j] == 1)
				ft_put_next_to_param(map, dim, i, j);
			if (params[i][j] == dim)
				ft_put_row_next_to_param(map, dim, i, j);
			j++;
		}
		i++;
	}
}

int	**ft_init_map(int **params, int dim)
{
	int	**map;

	map = ft_create_map(dim);
	if (!map)
		return (0);
	ft_fill_zeros(map, dim);
	ft_locate_predefined(map, params, dim);
	return (map);
}
