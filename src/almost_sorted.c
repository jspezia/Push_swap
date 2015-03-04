#include "push_swap.h"

static t_bool		check_one_swap(t_ps *ps)
{
	t_stack_node	*node;
	int				i;

	i = 0;
	node = FIRST(ps->stack_a);
	while (node->next)
	{
		if (CURR_VAL(node) > NEXT_VAL(node))
		{
			if (node->prev && CURR_VAL(node->prev) > NEXT_VAL(node))
				return (FALSE);
			i++;
		}
		node = node->next;
	}
	if (i != 1)
		return (FALSE);
	return (i);
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

void				solve_if_almost_sorted(t_ps *ps)
{
	int		position;

	push_stack(ps);
	if (check_one_swap(ps))
	{
		ps->options |= OPT_EXEC;
		position = position_sw(ps);
		select_node(position, ps);
		OP(SA);
		select_node(-position, ps);
		if (is_resolved(ps))
		{
			print_result(ps);
			free_all(ps);
			exit(-1);
		}
		else
			ps->options &= ~OPT_EXEC;
	}
}
