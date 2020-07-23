#include "../header/push_swap.h"

int ft_push_exit(char *str, t_ps *ps)
{
	if (*str)
	{
		ft_putstr(str);
	}
	free(ps->a);
	free(ps->b);
	return (0);
}

int ft_push_check3(t_ps *ps)
{
	int i;
	int s;

	i = -1;
	s = 0;
	while (++i < ps->lenA - 1)
		if (ps->a[i + 1] < ps->a[i])
			s++;
	if (ps->a[0] < ps->a[i])
		s++;
	return (s > 1 ? 0 : 1);
}


void ft_push_init(t_ps *ps, int length)
{
	ps->a = (int *)malloc(sizeof(int) * (length - 1 + 10));
	ps->b = (int *)malloc(sizeof(int) * (length - 1 + 10));
	ps->lenA = 0;
	ps->lenB = 0;
	ps->count = 0;
	ps->option = 0;
}

int ft_push_read(t_ps *ps, int length, char **actor)
{
	int i;
	int k;

	i = 0;
	while (++i < length)
	{
		ps->b[i - 1] = 0;
		ps->option += ft_strequ(actor[i], "-v") ? 1 : 0;
		ps->option += ft_strequ(actor[i], "-c") ? 2 : 0;
		if (ft_strequ(actor[i], "-v") == 0 && ft_strequ(actor[i], "-c") == 0)
		{
			IF_TRUE(ft_check_integer(actor[i]) == 0, return (1));
			k = -1;
			while (++k < ps->lenA)
				IF_TRUE(ps->a[k] == ft_atoi(actor[i]), return (1));
			ps->a[ps->lenA++] = ft_atoi(actor[i]);
		}
	}
	return (0);
}

void ft_push_print(char *str, char flag, t_ps *ps)
{
	if (ps->option != 100)
	{
		if (ps->option == 1 || ps->option == 3)
		{
			IF_TRUE(ps->option == 3, ft_putstr("\033[32m"));
			ft_putstr("\n\n# Step: ");
			ft_putnbr_fd(ps->count + 1, 1);
			IF_TRUE(ps->option == 3, ft_putstr("\033[36m"));
			ft_putstr("\nOperation: ");
		}
		ft_putstr(str);
		ft_putchar(flag);
		ft_putstr(ps->option == 1 || ps->option == 3 ? "" : "\n");
		IF_TRUE(ps->option == 3, ft_putstr("\033[0m"));
		if (ps->option == 1 || ps->option == 3)
		{
			ft_putstr("\nArray 'A': ");
			ft_array_print((*ps).a, ps->lenA);
			ft_putstr("\nArray 'B': ");
			ft_array_print((*ps).b, ps->lenB);
			ft_putstr("\nCount 'A': ");
			ft_putnbr_fd(ps->lenA, 1);
			ft_putstr("\nCount 'B': ");
			ft_putnbr_fd(ps->lenB, 1);
		}
	}
	ps->count += 1;
}
