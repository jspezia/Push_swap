#include "push_swap.h"

//--DBG--//

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

void			interactive_mode(t_op ops[11], t_ps *ps)
{
	char	*line;
	int		i;
	char	**tab;
	char	**tmp;

	line = NULL;
	while (get_next_line(1, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		tmp = tab;
		while (*tab)
		{
			i = 0;
			while (i < 11)
			{
				if (!(strcmp(*tab, ops[i].name)))
					ops[i].f(ps);
				i++;
			}
			tab++;
		}
		display_stacks(ps);
		free(line);
		free_tab(&tmp);
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
	parse(&ps, --ac, ++av);
	if (ps.options & OPT_INTERACTIVE)
		interactive_mode(ops, &ps); //
	//else
	//	algo();
	return (0);
}
