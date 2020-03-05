#include "fdf.h"

int		counter(char *str, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			res++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		while (str[i] == c)
			i++;
	}
	return (res);
}
//antooon + smbd = ?
