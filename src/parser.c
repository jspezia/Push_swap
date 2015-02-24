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

static void			recover_options(t_ps *ps, char *av)
{
	if (!(ft_strcmp(av, "-v")))
		ps->options |= OPT_VERBOSE;
	else if (!(ft_strcmp(av, "-c")))
		ps->options |= OPT_COLOR;
	else if (!(ft_strcmp(av, "-i")))
		ps->options |= OPT_INTERACTIVE;
	else if (!(ft_strcmp(av, "-t")))
		ps->options |= OPT_TIME;
	else
		ft_printf("%s: invalid option\n", av);
}

void				parse(t_ps *ps, int ac, char *av[])
{
	int		i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && !ft_isdigit(av[i][1]))
			recover_options(ps, av[i]);
		else
			fill_stack(ps->stack_a, av[i]);
		i++;
	}
}
