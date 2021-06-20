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

int	*ft_get_params_row(char **params, int dim)
{
	int	i;
	int	p;
	int	*row;

	row = malloc(sizeof(*row) * dim);
	if (!row)
		return (0);
	i = 0;
	while (i < dim)
	{
		p = ft_atoi(params[i]);
		if (p > 0 && p <= dim)
			row[i] = p;
		else
		{
			free(row);
			return (0);
		}
		i++;
	}
	return (row);
}

int	ft_preprocess_params(int ***res, char **params)
{
	int	dim;

	dim = ft_strs_count(params);
	if (dim % 4)
		return (0);
	dim /= 4;
	if (dim < 4 || dim > 9)
		return (0);
	if (!ft_is_input_numeric(params))
		return (0);
	*res = malloc(sizeof(**res) * 4);
	if (!(*res))
		return (0);
	return (dim);
}

int	ft_process_params(int ***res, char **params)
{
	int	i;
	int	dim;

	dim = ft_preprocess_params(res, params);
	if (!dim)
		return (0);
	i = 0;
	while (i < 4)
	{
		(*res)[i] = ft_get_params_row(params + i * dim, dim);
		if (!(*res)[i])
		{
			ft_free((void **) *res, i - 1);
			return (0);
		}
		i++;
	}
	return (dim);
}
