#include "ft_io.h"

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
