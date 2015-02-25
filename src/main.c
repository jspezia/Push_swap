#include "push_swap.h"

static int		loop_hook(t_env *e)
{
	// clear_img(e->img);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	printf("NO ENV\n");
	return (0);
}

static int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

void			mlx_handler(t_ps *ps)
{
	t_env	*e;

	e = init_env();
	// mlx_expose_hook(e->win, expose_hook, e);
	// sleep(100);
	// mlx_key_hook(e.win, key_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	// mlx_hook(e.win, MotionNotify, PointerMotionMask, pointer_motion_hook, &e);
	// mlx_loop_hook(e->mlx, loop_hook, e);
	// mlx_loop(e->mlx);
}

int				main(int ac, char *av[])
{
	t_ps		ps;
	t_op		ops[OPS_LEN] =
	{
		{"sa", &sa},
		{"sb", &sb},
		{"ss", &ss},
		{"pa", &pa},
		{"pb", &pb},
		{"ra", &ra},
		{"rb", &rb},
		{"rr", &rr},
		{"rra", &rra},
		{"rrb", &rrb},
		{"rrr", &rrr}
	};
	t_algo		algos[ALGOS_LEN] =
	{
		{"bbs", &bubble_sort},
		{"ff", &fifty_fifty},
		{"im", &interactive_mode}
	};

	if (ac == 1)
		error_msg_exit(USAGE);
	ps.stack_a = dlist_create();
	ps.stack_b = dlist_create();
	parse(&ps, algos, ac, av);
	mlx_handler(&ps);
	resolve(ops, &ps, &algos[ps.algo]);
	return (0);
}
