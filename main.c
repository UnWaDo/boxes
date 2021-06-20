#include <stdlib.h>

void	ft_print(char *str);

int		ft_is_input_correct(int *params);

int		ft_is_repeating(int **map);

void	ft_print_rect(int **map, int dim);

void	ft_put_next_to_param(int **map, int to_put, int sector, int position);

void	ft_put_to_all_copies(int **map, int to_put, int x, int y);

int		ft_locate_four(int **map, int *params);

int		ft_is_observed_correctly(int **map, int *params);

int		ft_is_filled(int **map);

int		ft_recursive_filling(int **map, int *params);

int		ft_try_fill (int **map, int *params, int x, int y);

int		ft_is_arguments_correct(int argc, char **argv, int *params);

char	**ft_split(char *str, char *sep);

void	ft_print_strs(char **strs);

int	ft_process_params(int ***res, char **params);

int	ft_is_recursion_end(int **map, int *params)
{
	if (ft_is_filled(map))
	{
		if (ft_is_observed_correctly(map, params))
		{
			//ft_print_rect(map, params);
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
	char	**params_raw;
	int		**params;
	int		i;
	int		n;

	if (argc != 2)
	{
		ft_print("Error\n");
		return (0);
	}
	params_raw = ft_split(argv[1], " \t\n\r\v");
	if (!params_raw)
	{
		ft_print("Error\n");
		return (0);
	}
	params = 0;
	n = ft_process_params(&params, params_raw);
	if (!n)
	{
		ft_print("Error\n");
		return (0);
	}
	ft_print_rect(params, n);
	i = 0;
	while (params_raw[i])
	{
		free(params_raw[i]);
		i++;
	}
	free(params_raw);
	i = 0;
	while (i < n)
	{
		free(params[i]);
		i++;
	}
	free(params);
	return (0);
}
