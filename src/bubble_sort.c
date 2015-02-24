
#include "push_swap.h"

t_bool			is_sort(t_dlist *stack)
{
	t_dlist_node	*node;
	int				nb1;
	int				nb2;

	node = stack->first;
	while (node && node->next)
	{
		nb1 = *(int *)node->value;
		nb2 = *(int *)node->next->value;
		if (nb1 > nb2)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

void			call_op(int op, t_op ops[11], t_ps *ps)
{
	ft_putendl(ops[op].name);
	ops[op].f(ps);
	display_stacks(ps);
	g_total_ops++;
	// sleep(1);
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
	t_dlist_node	*node_a;
	int				min;

	min = find_min(ps->stack_a->first);
	g_total_ops = 0;
	while (!is_sort(ps->stack_a))
	{
		node_a = ps->stack_a->first;
		if (*((int *)node_a->next->value) == min)
			call_op(RA, ops, ps);
		else if (*(int *)node_a->value > *(int *)node_a->next->value)
			call_op(SA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
	ft_putstr("SORTED! ops: ");
	ft_putnbr(g_total_ops);
	ft_putendl("!");
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
	while (count != ps->stack_a->count)
	{
		call_op(PB, ops, ps);
		count++;
	}
	min_a = find_min(ps->stack_a->first);
	min_b = find_min(ps->stack_b->first);
	while (!is_sort(ps->stack_b))
	{
		node_a = ps->stack_a->first;
		node_b = ps->stack_b->first;
		if (*((int *)node_a->next->value) == min_a && *((int *)node_a->next->value) == min_b)
			call_op(RR, ops, ps);
		else if (*((int *)node_a->next->value) == min_a)
			call_op(RA, ops, ps);
		else if (*((int *)node_b->next->value) == min_b)
			call_op(RB, ops, ps);
		//**********
		else if (*(int *)node_a->value > *(int *)node_a->next->value && *(int *)node_b->value > *(int *)node_b->next->value)
			call_op(SS, ops, ps);
		else if (*(int *)node_a->value > *(int *)node_a->next->value)
			call_op(SA, ops, ps);
		else if (*(int *)node_b->value > *(int *)node_b->next->value)
			call_op(SB, ops, ps);
		//**********
		else if (!is_sort(ps->stack_a))
			call_op(RR, ops, ps);
		else
			call_op(RB, ops, ps);
	}
	while (!is_sort(ps->stack_a))
	{
		node_a = ps->stack_a->first;
		if (*((int *)node_a->next->value) == min_a)
			call_op(RA, ops, ps);
		else if (*(int *)node_a->value > *(int *)node_a->next->value)
			call_op(SA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
	while (node_b)
	{
		node_b = ps->stack_b->first;
		node_a = ps->stack_a->first;
		if (*(int *)node_a->value > *(int *)node_b->value)
			call_op(PA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
	ft_putstr("SORTED! ops: ");
	ft_putnbr(g_total_ops);
	ft_putendl("!");
}



























