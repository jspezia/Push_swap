#ifndef PS_MLX
# define PS_MLX

# include <mlx.h>
# include <X11/Xutil.h>
# include <stdlib.h>
# include "libft.h"
# include "keys.h"

# define W_WIDTH	1000
# define W_HEIGHT	600

# define STACK_W	W_WIDTH
# define STACK_H	W_HEIGHT / 2

# define FACTOR		1
# define X_SIZE		4

typedef struct		s_img
{
	void		*id;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			lsize;
	int			endian;
}					t_img;

typedef struct		s_pt
{
	int			x;
	int			y;
}					t_pt;

typedef struct s_ps	t_ps;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_keys		*keys;
	t_ps		*ps;
}					t_env;

/*
**		env.c
*/
t_env	*mlx_env_instance(t_env *env);
void	free_env(t_env *e);
t_env	*init_env(t_ps *ps);

void	clear_image(t_img *img);
t_img	*create_new_image(t_env *e, int width, int height);

void	my_pixel_put_to_image(t_img *img, int x, int y, int color);
void	my_pixel_put_to_image_osx(t_img *img, int x, int y, int color);

void	draw_line(int color, t_pt *pt1, t_pt *pt2, t_img *img);

#endif
