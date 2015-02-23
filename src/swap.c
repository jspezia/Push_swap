#include "push_swap.h"

static void		swap(t_dlist *stack)
{
	void	*swap;

	if (stack->count < 2)
		return ;
	swap = stack->first->value;
	stack->first->value = stack->first->next->value;
	stack->first->next->value = swap;
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
