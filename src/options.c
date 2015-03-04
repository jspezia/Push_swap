#include "push_swap.h"

static void		display_help(void)
{
	char		*usage;

	usage = "[-hv] [-g [mode]] [-a algo] [-t delay] -- <int> <int> <...>\n";
	usage = ft_strjoin("./push_swap", usage);
	ft_putendl("\033[33mNAME\033[0m\n\tpush_swap\n");
	ft_putstr("\033[33mUSAGE\033[0m\n\t");
	ft_putendl(usage);
	ft_putendl("\033[33mOPTIONS\033[0m");
	ft_putendl("\t-h\t\tDisplay help.");
	ft_putendl("\t-c\t\tDisplay operations count.");
	ft_putendl("\t-a{algo}\t\tLet you specifie an algo {bbs, ff, up, se, me}.");
	ft_putendl("\t-i \t\tInteractive mode.");
	ft_putendl("\t-g{0, 1, 2}\tGraphic display.");
	ft_putstr("\t-t{delay}\t");
	ft_putendl("Let you add a delay in milliseconds between each op.");
	ft_putendl("\t-v\t\tVerbose. Display stack state at each step.");
	ft_putstr("\t--\t\tStop options parser, ");
	ft_putendl("in order to not treat negative values as options.");
	ft_putendl("\033[33mSUGGESTED\033[0m");
	ft_putendl("\t./push_swap -g0 -t200 -- <int> <int> <...>");
	exit(1);
}

static void		set_graphic_mode(t_ps *ps, char *optarg)
{
	ps->graphic_mode = optarg ? ft_atoi(optarg) : 0;
	ps->options |= OPT_GRAPHIC;
}

static void		set_algo(t_ps *ps, char *optarg)
{
	int		i;

	i = 0;
	while (i < ALGOS_LEN)
	{
		if (!ft_strcmp(optarg, g_algos[i].name))
		{
			ps->algo = i;
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

void			set_options(t_ps *ps, char opt)
{
	if (opt == 'a')
		set_algo(ps, optarg);
	else if (opt == 'h')
		display_help();
	else if (opt == 'v')
		ps->options |= OPT_VERBOSE;
	else if (opt == 'c')
		ps->options |= OPT_COUNT;
	else if (opt == 'i')
		ps->options |= OPT_INTERACTIVE;
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
