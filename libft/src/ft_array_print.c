#include "../header/libft.h"

void ft_array_print(int *array, int length)
{
	int i;

	i = -1;
	while (++i < length)
	{
		ft_putnbr_fd(array[i], 1);
		ft_putchar(' ');
	}
}
