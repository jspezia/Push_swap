#include "push_swap.h"

static void		display_help(void)
{
	ft_putendl(C(YELLOW)"NAME"C(NO)"\n\tpush_swap\n");
	ft_putendl(C(YELLOW)"USAGE"C(NO)"\n\t"USAGE"\n");
	ft_putendl(C(YELLOW)"OPTIONS"C(NO));
	ft_putendl("\t-h\t\tDisplay help.");
	ft_putendl("\t-a algo\t\tLet you specifie an algo {bbs, ff, up, ...}.");
	ft_putendl("\t-i\t\tInteractive mode.");
	ft_putendl("\t-g\t\tGraphic display.");
	ft_putendl("\t-t delay	Let you add a delay in milliseconds between each op.");
	ft_putendl("\t-v\t\tVerbose. Display stack state at each step.");
	ft_putendl("\t--\t\tStop options parser, in order to not treat negative values as options.");
	ft_putendl(C(YELLOW)"SUGGESTED"C(NO)"\n\t./push_swap -g -t200 -- <int> <int> <...>");
	exit(1);
}

static void		set_graphic_mode(t_ps *ps, char *optarg)
{
	ps->graphic_mode = optarg ? ft_atoi(optarg) : 0;
	ps->options |= OPT_GRAPHIC;
}

static void		set_algo(t_ps *ps, t_algo algos[ALGOS_LEN], char *optarg)
{
	int		i;

	i = 0;
	while (i < ALGOS_LEN)
	{
		if (!ft_strcmp(optarg, algos[i].name))
		{
			ps->algo = i;
			if (i == IM)
				ps->options |= OPT_INTERACTIVE;
			ps->options |= OPT_ALGO;
			return ;
		}
		i++;
	}
	ft_printf("-%c [%s]: invalid argument\n", optopt, optarg);
	exit(-1);
}

static void		handle_options_errors(char optopt)
{
	if (optopt == 't' || optopt == 'a')
		ft_printf("Option -%c requires an argument.\n", optopt);
	else
		ft_printf("Unknown option `-%c'.\n", optopt);
	exit(-1);
}

void			set_options(t_ps *ps, t_algo algos[ALGOS_LEN], char opt)
{
	if (opt == 'a')
		set_algo(ps, algos, optarg);
	else if (opt == 'h')
		display_help();
	else if (opt == 'v')
		ps->options |= OPT_VERBOSE;
	else if (opt == 'c')
		ps->options |= OPT_COLOR;
	else if (opt == 'i')
	{
		ps->algo = IM;
		ps->options |= OPT_INTERACTIVE;
	}
	else if (opt == 't')
	{
		ps->options |= OPT_TIME;
		if (!ft_str_isint(optarg) || ft_atoi(optarg) < 0)
			error_msg_exit("-t: invalid argument");
		ps->op_sleep = ft_atoi(optarg) * 1000;
	}
	else if (opt == 'g')
		set_graphic_mode(ps, optarg);
	else if (opt == '?')
		handle_options_errors(optopt);
}
