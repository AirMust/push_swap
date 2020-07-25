/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:26:16 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 22:37:44 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_ps_3(t_ps *ps)
{
	if (ft_push_check(ps) == 0)
	{
		if (ps->a_len == 3)
		{
			if (ft_push_check3(ps) == 0)
				ft_push_s(ps, 'a');
			if (ps->a[0] != ft_array_min(ps->a, ps->a_len))
			{
				if (ps->a[1] == ft_array_min(ps->a, ps->a_len))
					ft_push_r(ps, 'a');
				else
					ft_push_rr(ps, 'a');
			}
		}
		else if (ps->a_len != 3 && ft_push_check(ps) == 0)
			ft_push_s(ps, 'a');
	}
}

void	ft_sort_ps_40(t_ps *ps)
{
	int i;

	i = -1;
	while (ps->a_len > 3 && ft_push_check(ps) == 0)
	{
		ft_push_prev_ascent(ps, 'b');
	}
	ft_sort_ps_3(ps);
	while (ps->b_len)
	{
		ft_push_prev_ascent(ps, 'a');
	}
	i = -1;
	while (++i < ps->a_len)
		if (ps->a[i] == ft_array_min(ps->a, ps->a_len))
		{
			ft_push_iterate(ps, i, 'a', ps->a_len);
			break ;
		}
}

void	ft_sort_ps(int chank, int temp_chank, int ichank, t_ps *ps)
{
	int l;
	int i;

	if (ft_push_check(ps))
		return ;
	chank = 0;
	while (ps->a_len)
	{
		ichank++;
		l = 1;
		while (l != -1)
		{
			l = -1;
			i = -1;
			while (++i < ps->a_len)
				if (l == -1 && ps->a[i] <= temp_chank * ichank)
				{
					l = i;
					ft_push_iterate(ps, l, 'a', ps->a_len);
					ft_push_prev_ascent(ps, 'b');
				}
		}
	}
	ft_push_ascent(ps, 'b', 1, 0);
	while (ps->b_len > 0)
		ft_push_pa(ps);
}

int		main(int ac, char **av)
{
	int		i;
	int		chank;
	t_ps	*ps;

	ps = ft_push_init(ac);
	if (ft_push_read(ps, av) == 1)
		return (ft_push_exit("Error\n", ps));
	if (ps->a_len <= 3)
		ft_sort_ps_3(ps);
	else if (ps->a_len <= 40)
		ft_sort_ps_40(ps);
	else
	{
		chank = (ps->a_len) > 200 ? 12 : 5;
		i = (ft_array_max(ps->a, ps->a_len) -
		ft_array_min(ps->a, ps->a_len)) / chank;
		ft_sort_ps(chank, i, 0, ps);
	}
	return (ft_push_exit("", ps));
}
