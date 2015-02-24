#include "push_swap.h"

static t_bool	already_exists_in_stack(t_dlist *stack, int nb)
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

static void		fill_stack(t_dlist *stack, char *av)
{
	int		*nb;

	if (!ft_str_isint(av) || already_exists_in_stack(stack, ft_atoi(av)))
		error_msg_exit("Error");
	nb = (int *)malloc(sizeof(int));
	*nb = ft_atoi(av);
	dlist_push_back(stack, nb);
}

static void		set_algo(t_ps *ps, t_algo algos[ALGOS_LEN], char *optarg)
{
	int		i;

	i = 0;
	while (i < ALGOS_LEN)
	{
		if (!ft_strcmp(optarg, algos[i].name))
		{
			ps->algo = i;
			if (i == IM)
				ps->options |= OPT_INTERACTIVE;
			ps->options |= OPT_ALGO;
			return ;
		}
		i++;
	}
	ft_printf("-%c [%s]: invalid argument\n", optopt, optarg);
	exit(-1);
}

static void		set_options(t_ps *ps, t_algo algos[ALGOS_LEN], char opt)
{
	if (opt == 'a')
		set_algo(ps, algos, optarg);
	else if (opt == 'v')
		ps->options |= OPT_VERBOSE;
	else if (opt == 'c')
		ps->options |= OPT_COLOR;
	else if (opt == 'i')
		ps->options |= OPT_INTERACTIVE;
	else if (opt == 't')
	{
		ps->options |= OPT_TIME;
		if (!ft_str_isint(optarg) || ft_atoi(optarg) < 0)
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

void			parse(t_ps *ps, t_algo algos[ALGOS_LEN], int ac, char *av[])
{
	int		opt;
	int		i;

	opterr = 0;
	while ((opt = getopt(ac, av, "vcit:a:")) != -1)
	{
		set_options(ps, algos, opt);
	}
	i = optind;
	while (i < ac)
	{
		fill_stack(ps->stack_a, av[i]);
		i++;
	}
}
