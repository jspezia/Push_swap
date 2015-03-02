#include "push_swap.h"

t_bool			is_resolved(t_ps *ps)
{
	return ((!ps->stack_b->count) && is_stack_sorted(ps->stack_a));
}

int				find_min(t_stack *stack)
{
	int				min;
	t_stack_node	*cursor;

	cursor = FIRST(stack);
	min = cursor ? CURR_VAL(cursor) : 0;
	while (cursor)
	{
		min = fmin(min, CURR_VAL(cursor));
		cursor = cursor->next;
	}
	return (min);
}

void			call_op(int op, t_ps *ps)
{
	static size_t	op_index = 0;

	op_index++;
	if (ps->total_ops++ > MAX_OPS)
		error_msg_exit("KO -- MAX_OPS");
	if (OPT(OPT_TIME))
		usleep(ps->op_sleep);
	g_ops[op].f(ps);
	if (OPT(OPT_VERBOSE))
	{
		if (!(OPT(OPT_INTERACTIVE)))
			ft_putendl(g_ops[op].name);
		display_stacks(ps);
	}
	if (OPT(OPT_GRAPHIC))
	{
			if (FIRST(ps->stack_a) && (G_MODE(0)
				|| (G_MODE(1) && !(op_index % (ps->total_elem / 30)))
				|| (G_MODE(2) && CURR_VAL(FIRST(ps->stack_a)) == ps->range_min)))
				mlx_redraw(ps, g_ops[op].name);
	}
}

void			resolve(t_ps *ps)
{
	char	*tmp;

	if (OPT(OPT_GRAPHIC))
		mlx_redraw(ps, "Welcome");
	g_algos[ps->algo].f(ps);
	if (is_resolved(ps))
	{
		ft_printf("Sorted in "C(GREEN)"%d"C(NO)" ops!\n", ps->total_ops);
		if (OPT(OPT_GRAPHIC))
		{
			tmp = ft_strjoin3("Sorted in ", ft_itoa(ps->total_ops), " ops!");
			mlx_redraw(ps, tmp);
			free(tmp);
			sleep(EXIT_DELAY);
		}
	}
	else
		ft_putendl("Failed sorting!");
}
