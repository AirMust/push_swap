#include "../header/push_swap.h"

void ft_sort_ps_3(t_ps *ps)
{
	if (ft_push_check(ps) == 0)
	{
		if (ps->lenA == 3)
		{
			IF_TRUE(ft_push_check3(ps) == 0, ft_push_s(ps, 'a'));
			if (ps->a[0] != ft_array_min(ps->a, ps->lenA))
			{
				if (ps->a[1] == ft_array_min(ps->a, ps->lenA))
					ft_push_r(ps, 'a');
				else
					ft_push_rr(ps, 'a');
			}
		}
		else
			IF_FALSE(ft_push_check(ps), ft_push_s(ps, 'a'));
	}
}

void ft_sort_ps_40(t_ps *ps)
{
	int i;

	i = -1;
	while (ps->lenA > 3 && ft_push_check(ps) == 0)
	{
		ft_push_prev_ascent(ps, 'b');
	}
	ft_sort_ps_3(ps);
	while (ps->lenB)
	{
		ft_push_prev_ascent(ps, 'a');
	}
	i = -1;
	while (++i < ps->lenA)
		if (ps->a[i] == ft_array_min(ps->a, ps->lenA))
		{
			ft_push_iterate(ps, i, 'a', ps->lenA);
			break;
		}
}

void ft_sort_ps(int chank, int tempChank, int iChank, t_ps *ps)
{
	int l;
	int i;
	int arg;

	IF_TRUE(ft_push_check(ps), return );
	while (++iChank <= chank)
	{
		arg = tempChank * iChank;
		l = 1;
		while (l != -1)
		{
			l = -1;
			i = -1;
			while (++i < ps->lenA)
				if (l == -1 && ps->a[i] <= arg)
				{
					l = i;
					ft_push_iterate(ps, l, 'a', ps->lenA);
					ft_push_prev_ascent(ps, 'b');
				}
		}
	}
	ft_push_ascent(ps, 'b', 1, 0);
	while (ps->lenB > 0)
		ft_push_pa(ps);
}

int main(int ac, char **av)
{
	int i;
	int chank;
	t_ps ps;

	ft_push_init(&ps, ac);
	IF_TRUE(ft_push_read(&ps, ac, av) == 1, return (ft_push_exit("Error\n", &ps)));
	if (ps.lenA <= 3)
		ft_sort_ps_3(&ps);
	else if (ps.lenA <= 40)
		ft_sort_ps_40(&ps);
	else
	{
		chank = (ps.lenA) > 200 ? 12 : (ps.lenA) > 40 ? 5 : 2;
		i = (ft_array_max(ps.a, ps.lenA) - ft_array_min(ps.a, ps.lenA)) / chank;
		ft_sort_ps(chank, i, 0, &ps);
	}
	return (ft_push_exit("", &ps));
}
