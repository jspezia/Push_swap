#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include "push_swap.h"
#include <unistd.h>

void			ft_print_dlist(t_dlist *dlist, char *str)
{
	t_dlist_node	*node;

	node = dlist->last;
	if (str)
		ft_putstr(str);
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

void			ft_print_dlist2(t_list_ps *list)
{
	ft_print_dlist(list->a, "a: ");
	ft_print_dlist(list->b, "b: ");
}
