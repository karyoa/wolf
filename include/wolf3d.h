#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdio.h>
# include "../libft/incs/libft.h"
# include "mlx.h"

# define WIDTH 640
# define HEIGHT 480

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACEBAR 49

# define MOVESPEED 0.1
# define ROTSPEED 0.1

# define CR cos(ROTSPEED)
# define SR sin(ROTSPEED)
# define C_R cos(-ROTSPEED)
# define S_R sin(-ROTSPEED)

# define FOV 0.66

# define TEXTURE_WEST		"texture/floor1.xpm"
# define TEXTURE_EAST		"texture/floor2.xpm"
# define TEXTURE_NORTH		"texture/floor3.xpm"
# define TEXTURE_SOUTH		"texture/floor4.xpm"

typedef struct	s_ixy
{
	int 		x;
	int 		y;
}				t_ixy;

typedef struct	s_dxy
{
	double		x;
	double		y;
}				t_dxy;

typedef struct	s_map
{
	int			**wall;
	int			width;
	int			height;
}				t_map;

typedef struct	s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
}				t_player;

typedef struct	s_img
{
	int			width;
	int			height;
	char		*buffer;
	void		*img;
}				t_img;

typedef struct	s_keyboard
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			sleft;
	int			sright;
}				t_keyboard;

typedef struct	s_ray
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	map;
	struct s_dxy	dist;
	struct s_dxy	delta;
	struct s_dxy	step;
	double			cam;
	double		perpwalldist;
	int			hit;
	int 		hit_side;
	double		zbuffer[WIDTH];
}				t_ray;

typedef struct	s_mlx
{
	void 		*mlx;
	void 		*win;
	void 		*img;
	char 		*pxl;
	int 		bpp;
	int 		s_line;
	int 		endian;
}				t_mlx;

typedef struct	s_env
{
	struct s_mlx		mlx;
	struct s_player		player;
	struct s_ray 		ray;
	struct s_ixy		tex;
	struct s_img		*wall[10];
	struct s_map		map;
	char				*input;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					x;
	int					y;
	double				wallx;
	struct s_keyboard	key;
}				t_env;

/*
**	read.c
*/

void			read_params(t_env *e, char *input);

/*
**	setup_mlx.c
*/

void			setup_mlx(t_env *e);
void 			ft_error(char *error);
int				key_press_hook(int keycode, t_env *e);
int				key_release_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
t_list			*read_file(char	*filepath);
t_player		*newplayer(double x, double y);
t_dxy			newcoord(double x, double y);
void			ft_raycasting(t_env *e);
void			put_pxl(t_env *e, int x, int y, int color);
int				tchouin(int r, int g, int b);
int				getcolor(t_img *img, int x, int y, int fade);
void			drawbyside(t_env *e, int x, int y);
void			texture_load(t_env *e);
void			initkeyboard(t_env *e);
void			key_press(t_keyboard *key, int keycode);
void			key_release(t_keyboard *key, int keycode);
void			key_up_down(t_env *e);
void			key_left_right(t_env *e);
void			ft_draw(t_env *e, int x);
void			render(t_env *e);
void			ft_open_file(char *filepath);

#endif
