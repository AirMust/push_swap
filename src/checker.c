
#include "../header/push_swap.h"

int to_go_instr(char *instr, t_ps *ps)
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
		return ft_push_exit("Error", ps);
	return (1);
}

int parse_instr(t_ps *ps)
{
	char *instr;

	while (get_next_line(0, &instr) > 0)
	{
		if (to_go_instr(instr, ps) == 0)
		{
			free(instr);
			return (0);
		}
		free(instr);
	}
	if (instr && *instr)
		free(instr);
	return (1);
}

int main(int ac, char **av)
{
	t_ps ps;

	ft_push_init(&ps, ac);
	IF_TRUE(ft_push_read(&ps, ac, av) == 1, return (ft_push_exit("Error\n", &ps)));
	ps.option = 100;
	IF_TRUE(parse_instr(&ps) == 0, return (0));
	return (ft_push_check(&ps) == 1 && ps.lenB == 0 ? ft_push_exit("OK", &ps) : ft_push_exit("KO", &ps));
}
