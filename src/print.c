#include "push_swap.h"

void			print_stack(t_stack *dlist)
{
	t_stack_node	*cursor;

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
	ft_putstr("\033[""31""m""a: ""\033[""0""m");
	print_stack(ps->stack_a);
	ft_putstr("\033[""34""m""b: ""\033[""0""m");
	print_stack(ps->stack_b);
}
