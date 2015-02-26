#include "push_swap.h"

static t_op		g_ops[OPS_LEN] =
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

static t_algo	g_algos[ALGOS_LEN] =
{
	{"bbs", &bubble_sort},
	{"ff", &fifty_fifty},
	{"up", &up_down},
	{"im", &interactive_mode}
};

void			init_ps(t_ps *ps)
{
	t_env	*e;

	e = init_env(ps);
}

int				main(int ac, char *av[])
{
	t_ps	ps;

	if (ac < 2)
		error_msg_exit(USAGE);
	ft_bzero(&ps, sizeof(t_ps));
	ps.stack_a = dlist_create();
	ps.stack_b = dlist_create();
	parse(&ps, g_algos, ac, av);
	if (ps.options & OPT_GRAPHIC)
		init_ps(&ps);
	resolve(g_ops, &ps, &g_algos[ps.algo]);
	return (0);
}
