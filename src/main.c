#include "push_swap.h"

//--DBG--//

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

void			DBG(t_ps *ps)
{
	ft_putstr("a: ");
	ft_print_dlist(ps->stack_a);
	ft_putstr("b: ");
	ft_print_dlist(ps->stack_b);
}

void			test_ops(t_op ops[11], t_ps *ps)
{
	char	*line;
	int		i;
	char	**tab;

	line = NULL;
	while (get_next_line(1, &line) == 1)
	{
		tab = ft_strsplit(line, ' '); // not freed
		while (*tab)
		{
			i = 0;
			while (i < 11)
			{
				if (!(strcmp(*tab, ops[i].name)))
				{
					ops[i].f(ps);
				}
				i++;
			}
			tab++;
		}
		DBG(ps);
		free(line);
	}
}

//-------//

int				main(int ac, char *av[])
{
	t_ps		ps;
	t_op		ops[11] =
	{
		{"sa", &sa},
		{"sb", &sb},
		{"ss", &ss},
		{"pa", &pa},
		{"pb", &pb},
		{"ra", &ra},
		{"rb", &rb},
		{"rr", &rr},
		{"rra", &rra},
		{"rrb", &rrb},
		{"rrr", &rrr}
	};

	if (ac == 1)
		error_msg_exit("./push_swap <int> <int> <...>");
	ps.stack_a = dlist_create();
	ps.stack_b = dlist_create();
	parse(&ps, ++av);
	test_ops(ops, &ps); //
	return (0);
}
