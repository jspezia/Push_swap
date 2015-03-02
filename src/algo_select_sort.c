#include "push_swap.h"

static int		nb_elem_stack(t_stack *stack)
{
	int				i;
	int				value_origin;
	t_stack_node	*cursor;

	i = 0;
	cursor = FIRST(stack);
	value_origin = CURR_VAL(cursor);
	cursor = cursor->next;
	while (cursor && CURR_VAL(cursor) != value_origin)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

static int		min_position(t_stack *stack)
{
	int				min;
	int				nb_element;
	int				position;
	t_stack_node	*cursor;

	min = find_min(stack);
	nb_element = nb_elem_stack(stack);
	cursor = FIRST(stack);
	position = 0;
	while (CURR_VAL(cursor) != min)
	{
		position++;
		cursor = cursor->next;
	}
	if (nb_element - position - 2 < nb_element - (nb_element - position))
		return ((position - nb_element) - 1);
	return (position);
}

static void		select_node(int position, t_ps *ps)
{
	while (position != 0)
	{
		if (position > 0)
		{
			OP(RA);
			position--;
		}
		else if (position < 0)
		{
			OP(RRA);
			position++;
		}
	}
}

void			select_sort(t_ps *ps)
{
	t_stack_node		*node_a;
	t_stack_node		*node_b;
	int					position;

	node_a = FIRST(ps->stack_a);
	while (node_a)
	{
		position = min_position(ps->stack_a);
		select_node(position, ps);
		OP(PB);
		node_a = FIRST(ps->stack_a);
	}
	node_b = FIRST(ps->stack_b);
	while (node_b)
	{
		OP(PA);
		node_b = FIRST(ps->stack_b);
	}
}
