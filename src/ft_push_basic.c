/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:10:38 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 18:18:30 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_push_exit(char *str, t_ps *ps)
{
	if (*str)
	{
		ft_putstr(str);
	}
	free(ps->a);
	free(ps->b);
	free(ps);
	ps = NULL;
	return (0);
}

int		ft_push_check3(t_ps *ps)
{
	int	i;
	int	s;

	i = -1;
	s = 0;
	while (++i < ps->a_len - 1)
		if (ps->a[i + 1] < ps->a[i])
			s++;
	if (ps->a[0] < ps->a[i])
		s++;
	return (s > 1 ? 0 : 1);
}

t_ps	*ft_push_init(int length)
{
	t_ps *ps;

	ps = (t_ps *)malloc(sizeof(t_ps) * 1);
	ps->a = (int *)malloc(sizeof(int) * (length - 1 + 1000));
	ps->b = (int *)malloc(sizeof(int) * (length - 1 + 1000));
	ps->a_len = 0;
	ps->b_len = 0;
	ps->count = 0;
	ps->option = 0;
	return (ps);
}

int		ft_push_read_int(t_ps *ps, char *str)
{
	int k;

	if (ft_strequ(str, "-v") == 0 && ft_strequ(str, "-c") == 0)
	{
		if (ft_check_integer(str) == 0)
			return (1);
		k = -1;
		while (++k < ps->a_len)
			if (ps->a[k] == ft_atoi(str))
				return (1);
		ps->a[ps->a_len++] = ft_atoi(str);
	}
	return (0);
}

int		ft_push_read(t_ps *ps, char **av)
{
	int		i;
	int		j;
	char	**actor;

	j = 0;
	while (av[++j])
	{
		actor = ft_strsplit(av[j], ' ');
		i = -1;
		while (actor[++i])
		{
			ps->option += ft_strequ(actor[i], "-v") ? 1 : 0;
			ps->option += ft_strequ(actor[i], "-c") ? 2 : 0;
			ps->b[ps->a_len] = 0;
			if (ft_push_read_int(ps, actor[i]))
				return (1);
		}
		ft_strsplitfree(&actor);
	}
	return (0);
}
