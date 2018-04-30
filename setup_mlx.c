#include "wolf3d.h"

int		get_loop_hook(t_env *e)
{
	render(e);
	return (0);
}

void	setup_mlx(t_player *player, t_map *map;)
{
	t_env		e;

	e.map = map;
	e.player = player;
	e.mlx.mlx = mlx_init();
	e.mlx.win = mlx_new_window(e.mlx.mlx, WIDTH, HEIGHT, "Wolf3d");
	texture_load(&e);
	initkeyboard(&e);
	e.mlx.bpp = 0;
	e.mlx.s_line = 0;
	e.mlx.endian = 0;
	mlx_hook(e.mlx.win, 2, 1, key_press_hook, &e);
	mlx_hook(e.mlx.win, 3, 1, key_release_hook, &e);
	mlx_expose_hook(e.mlx.win, expose_hook, &e);
	mlx_loop_hook(e.mlx.mlx, get_loop_hook, &e);
	mlx_loop(e.mlx.mlx);
}

void	render(t_env *e)
{
	key_up_down(e);
	key_left_right(e);
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img,
	&(e->mlx.bpp), &(e->mlx.s_line), &(e->mlx.endian));
	raycast(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	mlx_destroy_image(e->mlx.mlx, e->mlx.img);
}
