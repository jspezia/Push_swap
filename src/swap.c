#include "push_swap.h"

static void		swap(t_dlist *stack)
{
	t_dlist_node	*node1;
	t_dlist_node	*node2;
	t_dlist_node	*node3;

	if (stack->count < 2)
		return ;
	node1 = stack->first;
	node2 = node1->next;
	node3 = node2->next;
	if (node3)
		node3->prev = node1;
	else
		stack->last = node1;
	node1->next =  node3;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	stack->first = node2;
}

void			sa(t_ps *ps)
{
	swap(ps->stack_a);
}

void			sb(t_ps *ps)
{
	swap(ps->stack_b);
}

void			ss(t_ps *ps)
{
	swap(ps->stack_a);
	swap(ps->stack_b);
}
