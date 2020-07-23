#include "../header/push_swap.h"

void ft_push_restruct(t_ps *ps, int **array, int *length, char flag)
{
	*array = flag == 'a' ? ps->a : ps->b;
	*length = flag == 'a' ? ps->lenA : ps->lenB;
}

void ft_push_construct(t_ps **ps, int *array, int length, char flag)
{
	IF_TRUE(flag == 'a', (*ps)->a = array);
	IF_TRUE(flag == 'b', (*ps)->b = array);
	IF_TRUE(flag == 'a', (*ps)->lenA = length);
	IF_TRUE(flag == 'b', (*ps)->lenB = length);
}

void ft_push_insert(int current, char flag, t_ps *ps)
{
	int i;
	int *array;
	int length;

	ft_push_restruct(ps, &array, &length, flag);
	length += 1;
	i = length;
	while (--i > 0)
		array[i] = array[i - 1];
	array[0] = current;
	ft_push_construct(&ps, array, length, flag);
}

void ft_push_remove(char flag, t_ps *ps)
{
	int i;
	int *array;
	int length;

	ft_push_restruct(ps, &array, &length, flag);

	length -= 1;
	i = -1;
	while (++i < length)
		array[i] = array[i + 1];
	ft_push_construct(&ps, array, length, flag);
}

int ft_push_check(t_ps *ps)
{
	int i;

	i = -1;
	while (++i < ps->lenA - 1)
		if (ps->a[i + 1] < ps->a[i])
			return (0);
	return (1);
}
