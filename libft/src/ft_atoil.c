#include "libft.h"

int	ft_isspace(char c)
{
	return ((c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ') ? 1 : 0);
}

long	ft_atoil(const char *str)
{
	int i;
	long n;
	int s;

	i = 0;
	n = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		IF_TRUE(str[i] == '-', s = -1);
		i++;
	}
	while (IS_DIGIT(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * s);
}
