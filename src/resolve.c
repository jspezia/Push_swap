#include "push_swap.h"

t_bool			is_resolved(t_ps *ps)
{
	return ((!ps->stack_b->count) && is_stack_sorted(ps->stack_a));
}

static void		print_op(t_ps *ps, int op)
{
	if (OPT(OPT_EXEC))
	{
		if (OPT(OPT_VERBOSE))
		{
			if (!(OPT(OPT_INTERACTIVE)))
				ft_putendl(g_ops[op].name);
			print_stacks(ps);
		}
		else if (!OPT(OPT_INTERACTIVE) && !(OPT(OPT_GRAPHIC)))
			ft_printf("%s ", g_ops[op].name);
		if (OPT(OPT_GRAPHIC))
		{
			if ((G_MODE(0)
			|| (G_MODE(1) && !(ps->total_ops % (ps->total_elem / 30 + 1)))
			|| (G_MODE(2) && CURR_VAL(FIRST(ps->stack_a)) == ps->range_min)))
				mlx_redraw(ps, g_ops[op].name);
		}
	}
}

void			call_op(int op, t_ps *ps)
{
	ps->total_ops++;
	if (OPT(OPT_EXEC) && OPT(OPT_TIME))
		usleep(ps->op_sleep);
	g_ops[op].f(ps);
	print_op(ps, op);
}

static void		execute(t_ps *ps)
{
	push_stack(ps);
	ps->total_ops = 0;
	if (OPT(OPT_GRAPHIC) && OPT(OPT_EXEC))
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
		ps->options |= OPT_EXEC;
		execute(ps);
	}
	print_result(ps);
}
