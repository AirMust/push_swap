/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:36:47 by slynell           #+#    #+#             */
/*   Updated: 2020/08/06 13:36:17 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	to_go_instr(char *instr, t_ps *ps)
{
	if (ft_strequ(instr, "sa"))
		ft_push_s(ps, 'a');
	else if (ft_strequ(instr, "sb"))
		ft_push_s(ps, 'b');
	else if (ft_strequ(instr, "ss"))
		ft_push_s_(ps);
	else if (ft_strequ(instr, "pa"))
		ft_push_pa(ps);
	else if (ft_strequ(instr, "pb"))
		ft_push_pb(ps);
	else if (ft_strequ(instr, "ra"))
		ft_push_r(ps, 'a');
	else if (ft_strequ(instr, "rb"))
		ft_push_r(ps, 'b');
	else if (ft_strequ(instr, "rr"))
		ft_push_r_(ps);
	else if (ft_strequ(instr, "rra"))
		ft_push_rr(ps, 'a');
	else if (ft_strequ(instr, "rrb"))
		ft_push_rr(ps, 'b');
	else if (ft_strequ(instr, "rrr"))
		ft_push_rr_(ps);
	else
		return (0);
	return (1);
}

int	parse_instr(t_ps *ps)
{
	char	*instr;
	int		temp;

	temp = 1;
	while (get_next_line(0, &instr) > 0)
	{
		temp = to_go_instr(instr, ps);
		if (temp == 0)
			break ;
		ft_strdel(&instr);
	}
	ft_strdel(&instr);
	return (temp);
}

int	main(int ac, char **av)
{
	t_ps	*ps;
	int		length;

	ps = ft_push_init(-1);
	if (ft_push_read_count(ps, av, ac) == 1)
		return (ft_push_exit("Error\n", ps));
	length = ps->a_len;
	if (length == 0)
		return (ft_push_exit("", ps));
	ft_push_free(ps);
	ps = ft_push_init(length);
	if (ft_push_read(ps, av, ac) == 1)
		return (ft_push_exit("Error\n", ps));
	ps->option = 100;
	if (parse_instr(ps) == 0)
		return (ft_push_exit("Error\n", ps));
	return (ft_push_check(ps) == 1 && ps->b_len == 0
	? ft_push_exit("OK", ps) : ft_push_exit("KO", ps));
}
