#include "push_swap.h"

const t_op		g_ops[OPS_LEN] =
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

const t_algo	g_algos[ALGOS_LEN] =
{
	{"bbs", &bubble_sort},
	{"ff", &fifty_fifty},
	{"up", &up_down},
	{"se", &select_sort},
	{"me", &merge_sort},
	{"im", &interactive_mode}
};

static void		free_all(t_ps *ps, t_env *e)
{
	if ((e = mlx_env_instance(NULL)))
		free_env(e);
	dlist_destroy(ps->stack_a);
	dlist_destroy(ps->stack_b);
	free(ps->origin_data);
	free(ps);
}

static t_ps		*init_ps(void)
{
	t_ps	*ps;

	if (!(ps = (t_ps *)ft_memalloc(sizeof(t_ps))))
		exit(-1);
	ps->algo = -1;
	return (ps);
}

int				main(int ac, char *av[])
{
	t_ps	*ps;
	t_env	*e;

	e = NULL;
	if (ac < 2)
		error_msg_exit(USAGE);
	ps = init_ps();
	parse(ps, ac, av);
	if (OPT(OPT_GRAPHIC))
		e = init_env();
	resolve(ps);
	free_all(ps, e);
	sleep(500);
	return (0);
}
