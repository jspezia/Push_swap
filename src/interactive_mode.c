#include "push_swap.h"

static void		print_prompt(void)
{
	ft_putstr("$> ");
}

static void		recover_and_call_op(char *op_name, t_ps *ps)
{
	int		i;

	i = 0;
	while (i < OPS_LEN)
	{
		if (ft_strequ(op_name, g_ops[i].name))
			OP(i);
		i++;
	}
}

void			interactive_mode(t_ps *ps)
{
	char	*line;
	char	**tab;
	char	**tmp;

	line = NULL;
	push_stack(ps);
	if (OPT(OPT_GRAPHIC))
		mlx_redraw(ps, "WELCOME");
	ft_putendl("\033[33m::Interactive mode::\033[0m");
	if (OPT(OPT_VERBOSE))
		display_stacks(ps);
	print_prompt();
	while (!is_resolved(ps) && get_next_line(1, &line) == 1)
	{
		if (ft_strequ(line, "exit"))
			exit(0);
		tab = ft_strsplit(line, ' ');
		tmp = tab;
		while (*tab)
		{
			recover_and_call_op(*tab, ps);
			tab++;
		}
		free(line);
		free_tab(&tmp);
		print_prompt();
	}
	display_result(ps);
}
