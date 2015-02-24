#include "push_swap.h"

void			interactive_mode(t_op ops[OPS_LEN], t_ps *ps)
{
	char	*line;
	char	**tab;
	char	**tmp;
	int		i;

	line = NULL;
	while (!is_sort(ps->stack_a) && get_next_line(1, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		tmp = tab;
		while (*tab)
		{
			i = 0;
			while (i < OPS_LEN)
			{
				if (!(strcmp(*tab, ops[i].name)))
					call_op(i, ops, ps);
				i++;
			}
			tab++;
		}
		free(line);
		free_tab(&tmp);
	}
}
