#include "ft_io.h"
#include "ft_memory.h"

int	ft_is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *sep)
{
	int	i;
	int	len;
	int	amount;

	len = 0;
	amount = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_in_str(str[i], sep))
		{
			if (len)
				amount++;
			len = 0;
		}
		else
			len++;
		i++;
	}
	if (len)
		amount++;
	return (amount);
}

int	ft_strlen_sep(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_in_str(str[i], sep))
		i++;
	return (i);
}

char	*ft_strldup(char *str, int n)
{
	int	i;
	char	*res;

	res = malloc(sizeof(*str) * (n + 1));
	if (!res)
		return (0);

	i = 0;
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char *str, char *sep)
{
	int		i;
	int		amount;
	char	**res;
	int		len;

	amount = ft_word_count(str, sep);
	res = malloc((amount + 1) * sizeof(*res));
	if (!res)
		return (0);	
	i = 0;
	while (i < amount)
	{
		if (!ft_is_in_str(*str, sep))
		{
			len = ft_strlen_sep(str, sep);
			res[i] = ft_strldup(str, len);
			if (!res[i])
			{
				ft_free((void **) res, i - 1);
				return (0);
			}
			i++;
			str += len - 1;
		}
		str++;
	}
	res[amount] = 0;
	return (res);
}
