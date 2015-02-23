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

void				fill_stack(t_dlist *stack, char *av[])
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
