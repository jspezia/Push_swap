#include "push_swap.h"

static t_bool		already_exists_in_stack(t_dlist *stack, int nb)
{
	t_dlist_node	*cursor;

	cursor = stack->first;
	while (cursor)
	{
		if (CURR_VAL(cursor) == nb)
			return (TRUE);
		cursor = cursor->next;
	}
	return (FALSE);
}

static void			fill_stack(t_dlist *stack, char *av)
{
	int		*nb;

	if (!ft_str_isint(av) || already_exists_in_stack(stack, ft_atoi(av)))
		error_msg_exit("Error");
	nb = (int *)malloc(sizeof(int));
	*nb = ft_atoi(av);
	dlist_push_back(stack, nb);
}

static void			set_options(t_ps *ps, char opt)
{
	if (opt == 'v')
		ps->options |= OPT_VERBOSE;
	else if (opt == 'c')
		ps->options |= OPT_COLOR;
	else if (opt == 'i')
		ps->options |= OPT_INTERACTIVE;
	else if (opt == 't')
	{
		ps->options |= OPT_TIME;
		if (!ft_str_isint(optarg))
			error_msg_exit("-t: invalid argument");
		ps->op_sleep = ft_atoi(optarg);
	}
	else if (opt == '?')
	{
		if (optopt == 't')
			ft_printf("Option -%c requires an argument.\n", optopt);
		else
			ft_printf("Unknown option `-%c'.\n", optopt);
	}
}

void				parse(t_ps *ps, int ac, char *av[])
{
	int		opt;
	int		i;

	opterr = 0;
	while ((opt = getopt(ac, av, "vcit:")) != -1)
	{
		set_options(ps, opt);
	}
	i = optind;
	while (i < ac)
	{
		fill_stack(ps->stack_a, av[i]);
		i++;
	}
}
