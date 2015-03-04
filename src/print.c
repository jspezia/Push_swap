#include "push_swap.h"

void			print_stack(t_stack *stack)
{
	t_stack_node	*cursor;

	cursor = LAST(stack);
	while (cursor)
	{
		ft_printf("%d ", CURR_VAL(cursor));
		cursor = cursor->prev;
	}
	ft_putchar('\n');
}

void			print_stacks(t_ps *ps)
{
	ft_putstr("\033[31ma: \033[0m");
	print_stack(ps->stack_a);
	ft_putstr("\033[34mb: \033[0m");
	print_stack(ps->stack_b);
}

void			print_result(t_ps *ps)
{
	char		*tmp;

	if (is_resolved(ps))
	{
		if (OPT(OPT_PRINT_OPS) && ps->total_ops)
			ft_putendl("\b");
		if (!OPT(OPT_PRINT_OPS) || OPT(OPT_COUNT))
			ft_printf("Sorted in \033[32m%d\033[0m ops!\n", ps->total_ops);
		if (OPT(OPT_GRAPHIC))
		{
			tmp = ft_strjoin3("Sorted in ", ft_itoa(ps->total_ops), " ops!");
			mlx_redraw(ps, tmp);
			free(tmp);
			sleep(EXIT_DELAY);
		}
	}
	else
		ft_putendl("Failed sorting!");
}
