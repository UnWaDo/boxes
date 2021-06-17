#include <stdlib.h>

void	ft_print(char *str);

void	ft_putchar(char c);

int		ft_process_params(int argc, char **argv, int *params);

int		ft_is_input_correct(int *params);

int		ft_is_repeating(int **map);

void	ft_print_rect(int **map, int *params);

void	ft_put_next_to_param(int **map, int to_put, int sector, int position);

void	ft_put_to_all_copies(int **map, int to_put, int x, int y);

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

int		ft_is_observed_correctly(int **map, int *params);

int		ft_is_filled(int **map);

int	ft_recursive_filling(int **map, int *params)
{
	int	i;
	int	j;
	int	k;
	int	success;

	success = 0;
	if (ft_is_filled(map))
	{
		if (ft_is_observed_correctly(map, params))
		{
			success = 1;
			ft_print_rect(map, params);
		}
		return (success);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] != 0)
			{
				j++;
				continue ;
			}
			k = 1;
			while (k <= 4)
			{
				ft_put_to_all_copies(map, k, i, j);
				if (!ft_is_repeating(map))
				{
					success = ft_recursive_filling(map, params);
					if (success)
						return (success);
				}
				k++;
			}
			ft_put_to_all_copies(map, 0, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_fill_rect(int *params)
{
	int	*map[16];
	int	i;
	int	j;

	i = 0;
	while (i < 16)
	{
		map[i] = malloc(4 * sizeof(int));
		j = 0;
		while (j < 4)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_print_rect(map, params);
	ft_locate_four(map, params);
	ft_print_rect(map, params);
	ft_recursive_filling(map, params);
	i = 0;
	while (i < 4)
	{
		free(map[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	params[16];
	int	status;

	if (argc <= 16)
	{
		ft_print("Not enough arguments\n");
		return (0);
	}
	else if (argc > 17)
	{
		ft_print("Too many arguments\n");
		return (0);
	}
	status = ft_process_params(argc, argv, params);
	if (!status)
	{
		ft_print("Invalid arguments input\n");
		return (0);
	}
	status = ft_is_input_correct(params);
	if (!status)
	{
		ft_print("Impossible transposition\n");
		return (0);
	}
	ft_fill_rect(params);
	return (0);
}
