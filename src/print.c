#include "push_swap.h"

void			ft_print_dlist(t_dlist *dlist)
{
	t_dlist_node	*node;

	node = dlist->last;
	while (node)
	{
		int *nb;
		nb = node->value;
		ft_putnbr(*nb);
		ft_putstr("  ");
		node = node->prev;
	}
	write(1, "\n", 1);
}
