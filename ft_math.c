int	ft_root(int n)
{
	long int	d;
	long int	square;
	int		i;

	if (n < 0)
		return (-1);
	d = 1;
	square = 0;
	i = 0;
	while (square <= n)
	{
		if (square == n)
			return (i);
		square += d;
		d += 2;
		i++;
	}
	return (-1);
}
