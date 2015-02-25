#include "push_swap.h"

static void		draw_stack(t_dlist *stack, t_env *e, int pos, int color)
{
	size_t			index;
	size_t			x;
	size_t			y;
	size_t			h;
	t_dlist_node	*cursor;

	cursor = FIRST(stack);
	index = 0;
	while (cursor)
	{
		x = 0;
		while (x < X_SIZE)
		{
			h = CURR_VAL(cursor);
			y = 0;
			while (y < h * FACTOR)
			{
				my_pixel_put_to_image(e->img, pos + index * X_SIZE + x, W_HEIGHT - y, color);
				y++;
			}
			x++;
		}
		index++;
		cursor = cursor->next;
	}
}

void			mlx_redraw(t_ps *ps)
{
	t_env			*e;

	e = mlx_env_instance(NULL);
	clear_image(e->img);
	draw_stack(ps->stack_a, e, 0, 0x0000FF);
	draw_stack(ps->stack_b, e, 500, 0x00FF00);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
}
