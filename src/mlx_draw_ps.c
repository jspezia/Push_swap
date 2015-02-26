#include "push_swap.h"

static void		draw_stack(t_stack *stack, t_ps *ps, t_env *e, int pos)
{
	size_t			index;
	double			x;
	double			y;
	double			w;
	double			h;
	t_dlist_node	*cursor;
	int				color;

	cursor = FIRST(stack);
	index = 0;
	w = (double)STACK_W / ps->total_elem;
	while (cursor)
	{
		h = ((double)STACK_H / ps->range) * (double)(CURR_VAL(cursor) - ps->range_min);
		color = e->palette[(int)((h / STACK_H) * PALETTE_SIZE)];
		x = 0;
		while (x < w)
		{
			y = 0;
			while (y < h)
			{
				int posx = index * w + x;
				int posy = pos + STACK_H - y;
				my_pixel_put_to_image(e->img, posx, posy, color);
				y++;
			}
			x++;
		}
		index++;
		cursor = cursor->next;
	}
}

void			mlx_redraw(t_ps *ps, char *op)
{
	t_env			*e;

	e = mlx_env_instance(NULL);
	// manage_keys(e);
	clear_image(e->img);
	draw_stack(ps->stack_a, ps, e, 0);
	draw_stack(ps->stack_b, ps, e, STACK_H);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 20, 0xFFFFFF, op);
}
