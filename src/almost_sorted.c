#include "push_swap.h"

static t_bool		check_status(t_stack *stack)
{
	t_stack_node	*node;
	int				i;

	i = 0;
	node = FIRST(stack);
	while (node->next)
	{
		if (CURR_VAL(node) > NEXT_VAL(node))
		{
			if (CURR_VAL(node) > CURR_VAL(LAST(stack))
				&& ((!node->next->next)
					|| NEXT_VAL(node->next) > NEXT_VAL(node)))
				i++;
			else
				i++;
		}
		node = node->next;
	}
	if (i == 1)
		return (TRUE);
	return (FALSE);
}

static int			position_sw(t_ps *ps)
{
	t_stack_node	*node;
	int				ptn;
	int				nb_elt;

	ptn = 0;
	nb_elt = (int)ps->total_elem;
	node = FIRST(ps->stack_a);
	while (node->next)
	{
		if (CURR_VAL(node) > NEXT_VAL(node))
		{
			if (nb_elt - ptn - 1 < nb_elt - (nb_elt - ptn))
				return ((ptn - nb_elt));
			return (ptn);
		}
		ptn++;
		node = node->next;
	}
}

t_bool				almost_sorted(t_ps *ps)
{
	int		position;

	push_stack(ps);
	if (check_status(ps->stack_a))
	{
		position = position_sw(ps);
		select_node(position, ps);
		OP(SA);
		select_node(-position, ps);
		return (TRUE);
	}
	return (FALSE);
}
