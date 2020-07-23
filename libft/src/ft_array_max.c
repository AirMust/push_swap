#include "../header/libft.h"

int ft_array_max(int *array, int len)
{
	int i;
	int max;

	max = INT32_MIN;
	i = -1;
	while (++i < len)
		if (max < array[i])
			max = array[i];
	return (max);
}
