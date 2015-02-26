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

static int		fill_stack(t_dlist *stack, char *av)
{
	int		*nb;

	if (!ft_str_isint(av) || already_exists_in_stack(stack, ft_atoi(av)))
		error_msg_exit("Error");
	nb = (int *)malloc(sizeof(int));
	*nb = ft_atoi(av);
	dlist_push_back(stack, nb);
	return (*nb);
}

static void		recover_range(t_ps *ps, int nb)
{
	static t_bool	first = TRUE;

	ps->range_min = first ? nb : fmin(ps->range_min, nb);
	ps->range_max = first ? nb : fmax(ps->range_max, nb);
	first = FALSE;
}

void			parse(t_ps *ps, t_algo algos[ALGOS_LEN], int ac, char *av[])
{
	int		opt;
	int		i;
	int		nb;

	opterr = 0;
	while ((opt = getopt(ac, av, OPT_STR)) != -1)
		set_options(ps, algos, opt);
	i = optind;
	if (i == ac)
		error_msg_exit("Missing <int> arguments.");
	while (i < ac)
	{
		nb = fill_stack(ps->stack_a, av[i]);
		recover_range(ps, nb);
		i++;
	}
	ps->total_elem = COUNT(ps->stack_a);
	ps->range = ps->range_max - ps->range_min + 1;
	// printf("Range: %d [%d, %d], N: %d\n", ps->range, ps->range_min, ps->range_max, ps->total_elem);
}
