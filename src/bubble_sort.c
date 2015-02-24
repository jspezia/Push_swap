
#include "push_swap.h"

t_bool			is_sort(t_dlist *stack)
{
	t_dlist_node	*node;
	int				nb1;
	int				nb2;


	node = stack->first;
	printf("first: %d\n", *(int *)stack->first->value);
	while (node && node->next)
	{
		nb1 = *(int *)node->value;
		nb2 = *(int *)node->next->value;
		if (nb1 > nb2)
		{
			printf("%d(%p) > %d(%p)\n", nb1, &nb1, nb2, &nb2);
			return (FALSE);
		}
		node = node->next;
	}
	return (TRUE);
}

int				sorted(t_dlist *stack)
{
	t_dlist_node	*cursor;

	cursor = stack->first;
	while (cursor)
	{
		printf("%d ", *(int *)cursor->value);
		cursor = cursor->next;
	}
	printf("\n");
	return (0);
}

void			call_op(int op, t_op ops[11], t_ps *ps)
{
	ft_putendl(ops[op].name);
	ops[op].f(ps);
	display_stacks(ps);
	g_total_ops++;
	sleep(1);
}

void			bubble_sort(t_op ops[11], t_ps *ps)
{
	t_dlist_node	*node_a;
	int				min;

	min = 1;
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
