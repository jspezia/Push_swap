#include "push_swap.h"

static t_bool		already_exists_in_stack(t_dlist *stack, int nb)
{
	t_dlist_node	*cursor;

	cursor = stack->first;
	while (cursor)
	{
		if ((*(int *)cursor->value) == nb)
			return (TRUE);
		cursor = cursor->next;
	}
	return (FALSE);
}

static void			fill_stack(t_dlist *stack, char *av[])
{
	int		*nb;

	while (*av)
	{
		if (!ft_str_isint(*av) || already_exists_in_stack(stack, ft_atoi(*av)))
			error_msg_exit("Error");
		nb = (int *)malloc(sizeof(int));
		*nb = ft_atoi(*av);
		dlist_push_back(stack, nb);
		av++;
	}
}

void				parse(t_ps *ps, char *av[])
{
	while (*av && *av[0] == '-')
	{
		if (!(ft_strcmp(*av, "-v")))
			ps->options |= OPT_VERBOSE;
		else if (!(ft_strcmp(*av, "-c")))
			ps->options |= OPT_COLOR;
		av++;
	}
	fill_stack(ps->stack_a, av);
}
