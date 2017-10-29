#include "push_swap.h"

static void		draw_a(double h, t_env *e, double w, int index)
{
	double		x;
	double		y;
	int			color;

	color = e->palette[(int)((h / STACK_H) * PALETTE_SIZE)];
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			my_pixel_put_to_image_osx(e->img, (index * w + x),
				STACK_H - y - 1, color);
			y++;
		}
		x++;
	}
}

static void		draw_b(double h, t_env *e, double w, int index)
{
	double		x;
	double		y;
	int			color;

	color = e->palette[(int)((h / STACK_H) * PALETTE_SIZE)];
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			my_pixel_put_to_image_osx(e->img, (index * w + x),
				W_HEIGHT - y - 1, color);
			y++;
		}
		x++;
	}
}

static void		draw_stack(t_stack *stack, t_ps *ps, t_env *e, int pos)
{
	size_t			index;
	double			w;
	double			h;
	t_dlist_node	*cursor;

	cursor = LAST(stack);
	index = 0;
	w = (double)STACK_W / ps->total_elem;
	while (cursor)
	{
		h = ((double)STACK_H / ps->range)
		* (double)(CURR_VAL(cursor) - ps->range_min);
		h = !h ? 1 : h;
		if (pos == 0)
			draw_a(h, e, w, index);
		else
			draw_b(h, e, w, index);
		index++;
		cursor = cursor->prev;
	}
}

void			mlx_redraw(t_ps *ps, char *op)
{
	t_env			*e;

	e = mlx_env_instance(NULL);
	clear_image(e->img);
	draw_stack(ps->stack_a, ps, e, 0);
	draw_stack(ps->stack_b, ps, e, STACK_H);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 20, 0xFFFFFF, op);
	mlx_do_sync(e->mlx);
}
