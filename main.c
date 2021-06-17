#include <stdlib.h>

void	ft_print(char *str);

int		ft_process_params(int argc, char **argv, int *params);

int		ft_is_input_correct(int *params);

int		ft_is_repeating(int **map);

void	ft_print_rect(int **map, int *params);

void	ft_put_next_to_param(int **map, int to_put, int sector, int position);

void	ft_put_to_all_copies(int **map, int to_put, int x, int y);

int		ft_locate_four(int **map, int *params);

int		ft_is_observed_correctly(int **map, int *params);

int		ft_is_filled(int **map);

int		ft_recursive_filling(int **map, int *params);

int		ft_try_fill (int **map, int *params, int x, int y);

int		ft_is_arguments_correct(int argc, char **argv, int *params);

int	ft_is_recursion_end(int **map, int *params)
{
	if (ft_is_filled(map))
	{
		if (ft_is_observed_correctly(map, params))
		{
			ft_print_rect(map, params);
			return (1);
		}
		return (-1);
	}
	return (0);
}

int	ft_recursive_filling(int **map, int *params)
{
	int	i;
	int	j;
	int	end;

	end = ft_is_recursion_end(map, params);
	if (end)
	{
		if (end == 1)
			return (1);
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			end = ft_try_fill(map, params, i, j);
			if (end)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_init_rect(int **map, int *params)
{
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
	ft_locate_four(map, params);
}

int	ft_fill_rect(int *params)
{
	int	*map[16];
	int	i;
	int	status;

	ft_init_rect(map, params);
	status = ft_recursive_filling(map, params);
	i = 0;
	while (i < 4)
	{
		free(map[i]);
		i++;
	}
	return (status);
}

int	main(int argc, char **argv)
{
	int	params[16];
	int	status;

	if (!ft_is_arguments_correct(argc, argv, params))
		return (0);
	status = ft_fill_rect(params);
	if (!status)
		ft_print("No possible transpositions\n");
	return (0);
}
