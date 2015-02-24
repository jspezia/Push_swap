#include "push_swap.h"

void			print_stack(t_dlist *dlist)
{
	t_dlist_node	*cursor;
	int				*nb;

	cursor = dlist->last;
	while (cursor)
	{
		nb = (int *)cursor->value;
		ft_putnbr(*nb);
		ft_putstr(" ");
		cursor = cursor->prev;
	}
	ft_putchar('\n');
}

void			display_stacks(t_ps *ps)
{
	ft_putstr("a: ");
	print_stack(ps->stack_a);
	ft_putstr("b: ");
	print_stack(ps->stack_b);
}
