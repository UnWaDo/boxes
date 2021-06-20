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

char	*ft_strldup(char **dest, char *str, char *sep)
{
	int		i;
	int		len;

	len = ft_strlen_sep(str, sep);
	*dest = malloc(sizeof(*str) * (len + 1));
	if (!(*dest))
		return (0);
	i = 0;
	while (i < len)
	{
		(*dest)[i] = str[i];
		i++;
	}
	(*dest)[i] = 0;
	return (str + i);
}

char	**ft_split(char *str, char *sep)
{
	int		i;
	int		amount;
	char	**res;

	amount = ft_word_count(str, sep);
	res = malloc((amount + 1) * sizeof(*res));
	if (!res)
		return (0);
	i = 0;
	while (i < amount)
	{
		if (!ft_is_in_str(*str, sep))
		{
			str = ft_strldup(res + i, str, sep) - 1;
			if (!res[i])
			{
				ft_free((void **) res, i - 1);
				return (0);
			}
			i++;
		}
		str++;
	}
	res[amount] = 0;
	return (res);
}
