#include "push_swap.h"

t_bool			is_resolved(t_ps *ps)
{
	return ((!ps->stack_b->count) && is_stack_sorted(ps->stack_a));
}

int				find_min(t_dlist *stack)
{
	int				min;
	t_dlist_node	*cursor;

	cursor = FIRST(stack);
	min = cursor ? CURR_VAL(cursor) : 0;
	while (cursor)
	{
		min = fmin(min, CURR_VAL(cursor));
		cursor = cursor->next;
	}
	return (min);
}

void			call_op(int op, t_op ops[OPS_LEN], t_ps *ps)
{
	if (ps->total_ops++ > MAX_OPS)
		error_msg_exit("KO -- MAX_OPS");
	if (OPT(OPT_TIME))
		usleep(ps->op_sleep);
	ops[op].f(ps);
	if (OPT(OPT_VERBOSE))
	{
		if (!(OPT(OPT_INTERACTIVE)))
			ft_putendl(ops[op].name);
		display_stacks(ps);
	}
	if (OPT(OPT_GRAPHIC))
		mlx_redraw(ps, ops[op].name);
	// printf("%s ", ops[op].name); // trick
}

void			resolve(t_op ops[OPS_LEN], t_ps *ps, t_algo *algo)
{
	char	*tmp;

	if (OPT(OPT_GRAPHIC))
		mlx_redraw(ps, "Welcome");
	algo->f(ops, ps);
	// printf("\n"); // trick end
	if (is_resolved(ps))
		ft_printf("Sorted in "C(GREEN)"%d"C(NO)" ops!\n", ps->total_ops); // not to print
	if (OPT(OPT_GRAPHIC))
	{
		tmp = ft_strjoin3("Sorted in ", ft_itoa(ps->total_ops), " ops!");
		mlx_redraw(ps, tmp);
		free(tmp);
	}
	sleep(200);
}
