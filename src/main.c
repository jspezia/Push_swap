#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include "push_swap.h"
#include <unistd.h>

t_dlist			*parse(char **av)
{
	t_dlist		*dlist;
	int			*nb;

	dlist = dlist_create();
	while (*av)
	{
		if (!ft_str_isint(*av))
			error_msg_exit(ft_strjoin(*(av), " is not an int."));
		nb = (int *)malloc((sizeof(int)));
		*nb = ft_atoi(*av++);
		dlist_push_back(dlist, nb);
	}
	return (dlist);
}

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

void			ft_print_dlist2(t_dlist *a, t_dlist *b)
{
	ft_print_dlist(a, "a: ");
	ft_print_dlist(b, "b: ");
}

void			exemples(t_dlist *dlist_a, t_dlist *dlist_b)
{
	ft_print_dlist2(dlist_a, dlist_b);
	sa(dlist_a);
	ft_print_dlist2(dlist_a, dlist_b);
	ft_putendl("ok");
}

int				main(int ac, char **av)
{
	t_dlist			*dlist_a;
	t_dlist			*dlist_b;

	if (ac == 1)
		error_msg_exit("./push_swap [list int]");
	dlist_a = parse(++av);
	dlist_b = dlist_create();
	exemples(dlist_a, dlist_b);
	return (0);
}
