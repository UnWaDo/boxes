#include "ft_io.h"

int	ft_is_n_occurs_once(int **params, int dim, int n)
{
	int	i;
	int	j;
	int	amount;

	i = 0;
	while (i < 4)
	{
		j = 0;
		amount = 0;
		while (j < dim && amount < 2)
		{
			if (params[i][j] == n)
				amount++;
			j++;
		}
		if (amount >= 2)
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_next_angle(int **params, int dim, int side)
{
	if (side == 0)
		return (params[3][0]);
	else if (side == 1)
		return (params[2][dim - 1]);
	else if (side == 2)
		return (params[0][0]);
	else
		return (params[1][dim - 1]);
}

int	ft_is_position_correct(int **params, int dim, int x, int y)
{
	if (params[x][y] == dim && params[(x / 2) *2 + (1 - x % 2)][y] != 1)
		return (0);
	if (params[x][y] == 1 && ft_get_next_angle(params, dim, x) != 1
		&& ((x / 2 + x % 2 + 1) % 2) * dim == y)
		return (0);
	else if (ft_get_next_angle(params, dim, x) == 1 && params[x][y] != 1
		&& ((x / 2 + x % 2 + 1) % 2) * dim == y)
		return (0);
	return (1);
}

int	ft_is_input_correct(int **params, int dim)
{
	int	i;
	int	j;

	i = 0;
	if (!ft_is_n_occurs_once(params, dim, 1))
		return (0);
	if (!ft_is_n_occurs_once(params, dim, dim))
		return (0);
	while (i < 4)
	{
		j = 0;
		while (j < dim)
		{
			if (!ft_is_position_correct(params, dim, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
