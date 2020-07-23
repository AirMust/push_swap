#include "libft.h"

int ft_check_integer(char *str)
{
	int i;

	i = 0;
	IF_TRUE(ft_strequ(str, "-") || ft_strequ(str, "+"), return (0));
	IF_TRUE(str[i] == '+' || str[i] == '-', i++);
	while (IS_DIGIT(str[i]))
		i++;
	IF_TRUE(str[i] != 0, return (0));
	i = ft_atoil(str) > INT32_MAX || ft_atoil(str) < INT32_MIN ? 0 : 1;
	return (i);
}
