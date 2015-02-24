
#include "push_swap.h"

t_bool			is_sort(t_dlist *stack)
{
	t_dlist_node	*cursor;
	int				nb1;
	int				nb2;

	cursor = stack->first;
	while (cursor && cursor->next)
	{
		nb1 = CURR_VAL(cursor);
		nb2 = NEXT_VAL(cursor);
		if (nb1 > nb2)
			return (FALSE);
		cursor = cursor->next;
	}
	return (TRUE);
}

void			call_op(int op, t_op ops[11], t_ps *ps)
{
	ft_putendl(ops[op].name);
	ops[op].f(ps);
	display_stacks(ps);
	g_total_ops++;
	if (ps->options & OPT_TIME)
		sleep(1);
}

void			resolve(t_op ops[11], t_ps *ps, t_algo *algo)
{
	g_total_ops = 0;

	algo->f(ops, ps);
	if (g_total_ops == MAX_OPS)
		ft_putendl("KO -- MAX_OPS");
	else
		ft_printf("Sorted in "C(GREEN)"%d"C(NO)" ops!\n", g_total_ops);
}

void			bubble_sort(t_op ops[11], t_ps *ps)
{
	t_dlist_node	*cursor;
	int				min;

	min = 1;
	while (!is_sort(ps->stack_a) && g_total_ops < MAX_OPS)
	{
		cursor = ps->stack_a->first;
		if (NEXT_VAL(cursor) == min)
			call_op(RA, ops, ps);
		else if (CURR_VAL(cursor) > NEXT_VAL(cursor))
			call_op(SA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
}
