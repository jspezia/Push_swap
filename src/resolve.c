#include "push_swap.h"

t_bool			is_resolved(t_ps *ps)
{
	return ((!ps->stack_b->count) && is_stack_sorted(ps->stack_a));
}

int				find_min(t_dlist_node *node)
{
	int		min;
	int		value;

	min = *(int *)node->value;
	while (node)
	{
		value = (*(int *)node->value);
		min = (value < min) ? value : min;
		node = node->next;
	}
	return (min);
}

void			call_op(int op, t_op ops[OPS_LEN], t_ps *ps)
{
	if (ps->options & OPT_TIME)
		sleep(ps->op_sleep);
	ops[op].f(ps);
	ps->total_ops++;
	if (ps->options & OPT_VERBOSE)
	{
		if (!(ps->options & OPT_INTERACTIVE))
			ft_putendl(ops[op].name);
		display_stacks(ps);
	}
}

void			resolve(t_op ops[OPS_LEN], t_ps *ps, t_algo *algo)
{
	ps->total_ops = 0;

	algo->f(ops, ps);
	if (ps->total_ops == MAX_OPS)
		ft_putendl("KO -- MAX_OPS");
	else
		ft_printf("Sorted in "C(GREEN)"%d"C(NO)" ops!\n", ps->total_ops);
}
