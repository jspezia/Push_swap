#include "push_swap.h"

t_bool			is_resolved(t_ps *ps)
{
	return ((!ps->stack_b->count) && is_stack_sorted(ps->stack_a));
}

int				find_min(t_stack *stack)
{
	int				min;
	t_stack_node	*cursor;

	cursor = FIRST(stack);
	min = cursor ? CURR_VAL(cursor) : 0;
	while (cursor)
	{
		min = fmin(min, CURR_VAL(cursor));
		cursor = cursor->next;
	}
	return (min);
}

void			call_op(int op, t_ps *ps)
{
	static size_t	op_index = 0;


	op_index++;
	ps->total_ops++;
	// if (gps->total_ops > MAX_OPS)
		// error_msg_exit("KO -- MAX_OPS");
	if (OPT(OPT_TIME))
		usleep(ps->op_sleep);
	g_ops[op].f(ps);
	if (OPT(OPT_VERBOSE))
	{
		if (!(OPT(OPT_INTERACTIVE)))
			ft_putendl(g_ops[op].name);
		display_stacks(ps);
	}
	if (OPT(OPT_GRAPHIC))
	{
		if (FIRST(ps->stack_a) && (G_MODE(0)
			|| (G_MODE(1) && !(op_index % (ps->total_elem / 30)))
			|| (G_MODE(2)
				&& CURR_VAL(FIRST(ps->stack_a)) == ps->range_min)))
			mlx_redraw(ps, g_ops[op].name);
	}
}

// void			resolve2(t_ps *ps)
// {
// 	char	*tmp;

// 	if (OPT(OPT_GRAPHIC))
// 		mlx_redraw(ps, "Welcome");
// 	g_algos[ps->algo].f(ps);
// 	if (is_resolved(ps))
// 	{
// 		ft_printf("Sorted in ""\033[""32""m""%d""\033[""0""m"" ops!\n",
// 			ps->total_ops);
// 		if (OPT(OPT_GRAPHIC))
// 		{
// 			tmp = ft_strjoin3("Sorted in ", ft_itoa(ps->total_ops), " ops!");
// 			mlx_redraw(ps, tmp);
// 			free(tmp);
// 			sleep(EXIT_DELAY);
// 		}
// 	}
// 	else
// 		ft_putendl("Failed sorting!");
// }


void			push_stack(t_ps *ps)
{
	size_t	i;

	if (ps->stack_a)
	{
		ft_putstr("Ahere\n");
		dlist_destroy(ps->stack_a);
	}
	if (ps->stack_b)
		dlist_destroy(ps->stack_b);
	ps->stack_a = dlist_create();
	ps->stack_b = dlist_create();
	ft_putstr("here\n");
	i = 0;
	while (i < ps->total_elem)
	{
		ft_putnbr(ps->origin_data[i]);
		i++;
	}
	ft_putstr("\n");
	i = 0;
	while (i < ps->total_elem)
	{
		dlist_push_back(ps->stack_a, &(ps->origin_data[i]));
		i++;
	}
	display_stacks(ps);
}

void			execute(t_ps *ps)
{
	ft_printf("here algo: %d\n", ps->algo);
	push_stack(ps);
	ps->total_ops = 0;
	g_algos[ps->algo].f(ps);
	ft_printf("here\n");
}

void			resolve(t_ps *ps)
{
	size_t		tmp_total_ops;

	if (ps->algo != -1)
		execute(ps);
	else
	{
		ps->algo = ps->total_elem > 500 ? SE : 0;
		tmp_total_ops = 0;
		while (ps->algo < ALGOS_LEN - 1) // No IM
		{
			execute(ps);
			if (is_resolved(ps) &&
				(!tmp_total_ops || ps->total_ops < tmp_total_ops))
			{
				ps->final_algo = ps->algo;
				tmp_total_ops = ps->total_ops;
			}
			ps->algo++;
		}
		ft_printf("FINAL ALGO: %d\n", ps->final_algo);
	}
}
