#include "ft_io.h"
#include "ft_strings.h"
#include "ft_memory.h"

int		ft_process_params(int ***res, char **params);
int		ft_is_input_correct(int **params, int dim);
void	ft_print_rect(int **map, int dim);
int		**ft_init_map(int **params, int dim);
int		ft_find_empty_cell(int **map, int **params, int dim);

int	ft_is_argv_ok(int argc, char **argv, int ***res)
{
	char	**params_raw;
	int		n;

	if (argc != 2)
		return (0);
	params_raw = ft_split(argv[1], " \t\n\r\v");
	if (!params_raw)
		return (0);
	n = ft_process_params(res, params_raw);
	if (!n)
	{
		ft_free_strs(params_raw);
		return (0);
	}
	if (!ft_is_input_correct(*res, n))
	{
		ft_free_strs(params_raw);
		ft_free((void **) *res, n);
		return (0);
	}
	ft_free_strs(params_raw);
	return (n);
}

int	main(int argc, char **argv)
{
	int		**params;
	int		**map;
	int		n;
	int		res;

	n = ft_is_argv_ok(argc, argv, &params);
	if (!n)
	{
		ft_print("Error\n");
		return (0);
	}
	map = ft_init_map(params, n);
	if (!map)
	{
		ft_print("Error\n");
		ft_free((void **) params, n);
		return (0);
	}
	res = ft_find_empty_cell(map, params, n);
	if (!res)
	{
		ft_print("Error\n");
		ft_print_rect(map, n);
		ft_free((void **) map, n);
		ft_free((void **) params, n);
		return (0);
	}
	ft_print_rect(map, n);
	ft_free((void **) map, n);
	ft_free((void **) params, n);
	return (0);
}
