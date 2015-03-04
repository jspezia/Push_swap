#include "push_swap.h"

static void		rotate(t_stack *stack)
{
	if (stack->count)
		dlist_push_back(stack, dlist_pop_front(stack));
}

void			ra(t_ps *ps)
{
	rotate(ps->stack_a);
}

void			rb(t_ps *ps)
{
	rotate(ps->stack_b);
}

void			rr(t_ps *ps)
{
	rotate(ps->stack_a);
	rotate(ps->stack_b);
}
