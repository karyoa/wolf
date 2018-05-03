/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:10:11 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/03 11:13:49 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define FOV 0.66

# define TEXT_W "texture/wall1v.xpm"
# define TEXT_E	"texture/wall2v.xpm"
# define TEXT_N	"texture/wall3v.xpm"
# define TEXT_S	"texture/wall4v.xpm"
# define TEXT_F	"texture/ceil1.xpm"
# define TEXT_P "texture/ceil4.xpm"

typedef struct	s_ixy
{
	int	x;
	int	y;
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
	double			perpwalldist;
	int				hit;
	int				hit_side;
}				t_ray;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pxl;
	int		bpp;
	int		s_line;
	int		endian;
}				t_mlx;

typedef struct	s_env
{
	struct s_mlx		mlx;
	struct s_player		player;
	struct s_ray		ray;
	struct s_ixy		tex;
	struct s_img		*wall[6];
	struct s_map		map;
	char				*input;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					x;
	int					y;
	double				wallx;
	struct s_dxy		floor;
	struct s_ixy		floortex;
	struct s_dxy		curfloor;
	double				walldist;
	double				playerdist;
	double				currentdist;
	double				weight;
	struct s_keyboard	key;
	int					i;
}				t_env;

/*
**	read.c
*/

void			read_params(t_env *e, char *input);

/*
**	setup_mlx.c
*/

void			setup_mlx(t_env *e);

/*
**	move.c
*/

void			key_up_down(t_env *e);
void			key_left_right(t_env *e);

/*
**	main.c
*/

void			ft_error(char *error);

/*
**	keyhook.c
*/

void			key_press(t_keyboard *key, int keycode);
void			key_release(t_keyboard *key, int keycode);
int				key_press_hook(int keycode, t_env *e);
int				key_release_hook(int keycode, t_env *e);
int				red_cross(int i);

/*
**	raycast.c
*/

void			ft_raycasting(t_env *e);

/*
**	draw.c
*/

void			put_pxl(t_env *e, int x, int y, int color);
int				getcolor(t_img *img, int x, int y, int fade);

/*
**	raydraw.c
*/

void			ft_draw(t_env *e, int x);
void			ft_open_file(char *filepath);

#endif
