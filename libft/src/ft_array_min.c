#include "../header/libft.h"

int ft_array_min(int *array, int len)
{
	int i;
	int min;

	min = INT32_MAX;
	i = -1;
	while (++i < len)
		if (min > array[i])
			min = array[i];
	return (min);
}
