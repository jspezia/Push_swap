#include "push_swap.h"

t_bool			is_resolved(t_ps *ps)
{
	return ((!ps->stack_b->count) && is_stack_sorted(ps->stack_a));
}

void			call_op(int op, t_ps *ps)
{
	static size_t	op_index = 0;

	op_index++;
	ps->total_ops++;
	if (OPT(OPT_RESULT) && OPT(OPT_TIME))
		usleep(ps->op_sleep);
	g_ops[op].f(ps);
	if (OPT(OPT_RESULT))
	{
		if (OPT(OPT_VERBOSE))
		{
			if (!(OPT(OPT_INTERACTIVE)))
				ft_putendl(g_ops[op].name);
			display_stacks(ps);
		}
		else if (!OPT(OPT_INTERACTIVE))
			ft_printf("%s ", g_ops[op].name);
		if (OPT(OPT_GRAPHIC))
		{
			if ((G_MODE(0)
				|| (G_MODE(1) && !(op_index % (ps->total_elem / 30 + 1)))
				|| (G_MODE(2) && CURR_VAL(FIRST(ps->stack_a)) == ps->range_min)))
				mlx_redraw(ps, g_ops[op].name);
		}
	}
}

static void		execute(t_ps *ps)
{
	push_stack(ps);
	ps->total_ops = 0;
	if (OPT(OPT_GRAPHIC) && OPT(OPT_RESULT))
		mlx_redraw(ps, "WELCOME");
	g_algos[ps->algo].f(ps);
}

void			resolve(t_ps *ps)
{
	size_t		tmp_total_ops;
	int			final_algo;

	if (ps->algo != -1)
		execute(ps);
	else
	{
		ps->algo = ps->total_elem > 500 ? SE : 0;
		tmp_total_ops = 0;
		while (ps->algo < ALGOS_LEN)
		{
			execute(ps);
			if (is_resolved(ps) &&
				(!tmp_total_ops || ps->total_ops < tmp_total_ops))
			{
				final_algo = ps->algo;
				tmp_total_ops = ps->total_ops;
			}
			ps->algo++;
		}
		ps->algo = final_algo;
		ps->options |= OPT_RESULT;
		execute(ps);
	}
	display_result(ps);
}
