#include "push_swap.h"

static void		reverse(t_dlist *stack)
{
	if (stack->count)
		dlist_push_front(stack, dlist_pop_back(stack));
	g_last1 = stack->first->value;
}

void			rra(t_ps *ps)
{
	reverse(ps->stack_a);
}

void			rrb(t_ps *ps)
{
	reverse(ps->stack_b);
}

void			rrr(t_ps *ps)
{
	reverse(ps->stack_a);
	reverse(ps->stack_b);
}
