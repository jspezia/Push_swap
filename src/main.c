#include "push_swap.h"

int				main(int ac, char *av[])
{
	t_ps		ps;
	t_op		ops[OPS_LEN] =
	{
		{"sa", &sa},
		{"sb", &sb},
		{"ss", &ss},
		{"pa", &pa},
		{"pb", &pb},
		{"ra", &ra},
		{"rb", &rb},
		{"rr", &rr},
		{"rra", &rra},
		{"rrb", &rrb},
		{"rrr", &rrr}
	};
	t_algo		algos[ALGOS_LEN] =
	{
		{"bbs", &bubble_sort},
		{"ff", &fifty_fifty},
		{"im", &interactive_mode}
	};

	if (ac == 1)
		error_msg_exit("./push_swap [-vci] [-a]<algo> [-t]<delay> <int> <int> <...>");
	ps.stack_a = dlist_create();
	ps.stack_b = dlist_create();
	parse(&ps, algos, ac, av);
	resolve(ops, &ps, &algos[ps.algo]);
	return (0);
}
