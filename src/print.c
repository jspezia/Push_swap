#include "push_swap.h"

void			print_stack(t_dlist *dlist)
{
	t_dlist_node	*cursor;
	int				*nb;

	cursor = dlist->last;
	while (cursor)
	{
		nb = (int *)cursor->value;
		if (nb == g_last1 || nb == g_last2)
		{
			ft_putstr(C(GREEN));
			ft_putnbr(*nb);
			ft_putstr(C(NO));
		}
		else
			ft_putnbr(*nb);
		ft_putstr(" ");
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
