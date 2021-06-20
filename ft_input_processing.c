#include "ft_io.h"
#include "ft_strings.h"
#include "ft_memory.h"

int	ft_strs_count(char **params)
{
	int	i;

	i = 0;
	while (params[i])
		i++;
	return (i);
}

int	ft_is_input_numeric(char **params)
{
	int	i;
	int	j;

	i = 0;
	while (params[i])
	{
		j = 0;
		while (params[i][j])
		{
			if (params[i][j] < '0' || params[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_process_params(int ***res, char **params)
{
	int	i;
	int	j;
	int	p;
	int	dim;

	dim = ft_strs_count(params);
	if (dim % 4)
		return (0);
	dim /= 4;
	if (dim < 4)
		return (0);
	if (!ft_is_input_numeric(params))
		return (0);
	*res = malloc(sizeof(**res) * 4);
	if (!(*res))
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		(*res)[i] = malloc(sizeof(***res) * dim);
		if (!(*res)[i])
		{
			ft_free((void **) *res, i - 1);
			return (0);
		}
		while (j < dim)
		{
			p = ft_atoi(params[4 * i + j]);
			if (p > 0 && p <= dim)
				(*res)[i][j] = p;
			else
			{
				ft_free((void **) *res, i - 1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (dim);
}
