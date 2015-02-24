#include "push_swap.h"

void			print_stack(t_dlist *dlist)
{
	t_dlist_node	*cursor;

	cursor = dlist->last;
	while (cursor)
	{
		ft_printf("%d ", CURR_VAL(cursor));
		cursor = cursor->prev;
	}
	ft_putchar('\n');
}

void			display_stacks(t_ps *ps)
{
	ft_putstr(C(RED)"a: "C(NO));
	print_stack(ps->stack_a);
	ft_putstr(C(BLUE)"b: "C(NO));
	print_stack(ps->stack_b);
}
