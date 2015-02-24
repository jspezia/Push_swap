
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

t_bool			is_sort2(t_dlist *stack)
{
	t_dlist_node	*cursor;
	int				nb1;
	int				nb2;

	cursor = stack->first;
	while (cursor && cursor->next)
	{
		nb1 = CURR_VAL(cursor);
		nb2 = NEXT_VAL(cursor);
		if (nb1 < nb2)
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

void			bubble_sort(t_op ops[11], t_ps *ps)
{
	t_dlist_node	*cursor;
	int				min;

	min = find_min(ps->stack_a->first);
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


void			fifty_fifty(t_op ops[11], t_ps *ps)
{
	t_dlist_node	*node_a;
	t_dlist_node	*node_b;
	int				min_a;
	int				min_b;
	int				count;

	g_total_ops = 0;
	count = 0;
	while (count <= ps->stack_a->count / 2)
	{
		call_op(PB, ops, ps);
		count++;
	}
	min_a = find_min(ps->stack_a->first);
	min_b = find_min(ps->stack_b->first);
	while (!is_sort2(ps->stack_b))
	{
		node_a = ps->stack_a->first;
		node_b = ps->stack_b->first;
		if (NEXT_VAL(node_a) == min_a && NEXT_VAL(node_b) == min_b)
			call_op(RR, ops, ps);
		else if (NEXT_VAL(node_a) == min_a)
			call_op(RA, ops, ps);
		else if (NEXT_VAL(node_b) == min_b)
			call_op(RB, ops, ps);
		//**********
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a) && CURR_VAL(node_b) > NEXT_VAL(node_b))
			call_op(SS, ops, ps);
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a))
			call_op(SA, ops, ps);
		else if (CURR_VAL(node_b) > NEXT_VAL(node_b))
			call_op(SB, ops, ps);
		//**********
		else if (!is_sort(ps->stack_a))
			call_op(RR, ops, ps);
		else
			call_op(RB, ops, ps);
	}
	ft_putendl("stack_b sorted !");
	while (!is_sort(ps->stack_a))
	{
		node_a = ps->stack_a->first;
		if (NEXT_VAL(node_a) == min_a)
			call_op(RA, ops, ps);
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a))
			call_op(SA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
	ft_putendl("stack_a sorted !");
	node_b = ps->stack_b->first;
	while (node_b)
	{
		node_a = ps->stack_a->first;
		if (CURR_VAL(node_a) > CURR_VAL(node_b))
			call_op(PA, ops, ps);
		else
			call_op(RA, ops, ps);
		node_b = ps->stack_b->first;
	}
}



























