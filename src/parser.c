#include "push_swap.h"

static t_bool	already_exists_in_tab(int *tab, int size, int value)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void		recover_range(t_ps *ps, int nb)
{
	static t_bool	first = TRUE;

	ps->range_min = first ? nb : fmin(ps->range_min, nb);
	ps->range_max = first ? nb : fmax(ps->range_max, nb);
	first = FALSE;
}

static int		*parse_int_values(t_ps *ps, int ac, char **av)
{
	int		i;
	int		*tab;

	if (!(tab = (int *)ft_memalloc(sizeof(int) * ac)))
		error_msg_exit("Allocation failed!");
	i = 0;
	while (i < ac)
	{
		if (!ft_str_isint(av[i])
			|| already_exists_in_tab(tab, i, ft_atoi(av[i])))
			error_msg_exit("Error");
		tab[i] = ft_atoi(av[i]);
		recover_range(ps, tab[i]);
		i++;
	}
	return (tab);
}

void			parse(t_ps *ps, int ac, char *av[])
{
	int		opt;
	int		nb;

	opterr = 0;
	while ((opt = getopt(ac, av, OPT_STR)) != -1)
		set_options(ps, opt);
	ac -= optind;
	if (!ac)
		error_msg_exit("Missing <int> arguments.");
	ps->origin_data = parse_int_values(ps, ac, av + optind);
	ps->total_elem = ac;
	ps->range = ps->range_max - ps->range_min + 1;
}
