#include "wolf3d.h"

void	initkeyboard(t_env *e)
{
	e->key.up = 0;
	e->key.down = 0;
	e->key.left = 0;
	e->key.right = 0;
	e->key.sleft = 0;
	e->key.sright = 0;
}

// int		loop_hook(t_env *e)
// {
// 	if (e->player.move_up)
// 		move_up(e);
// 	if (e->player.move_down)
// 		move_down(e);
// 	if (e->player.move_right)
// 		move_right(e);
// 	if (e->player.move_left)
// 		move_left(e);
// 	raycasting(e);
// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->test, 0, 0);
// 	return (0);
// }
//
// void 	key_move(t_env *e, int k)
// {
// 	if (k == KEY_UP)
// 		e->player.move_up = !e->player.move_up;
// 	if (k == KEY_DOWN)
// 		e->player.move_down = !e->player.move_down;
// 	if (k == KEY_LEFT)
// 		e->player.move_left = !e->player.move_left;
// 	if (k == KEY_RIGHT)
// 		e->player.move_right = !e->player.move_right;
// 	if (k == KEY_ESC)
// 	{
// 		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
// 		exit(0);
// 	}
// }

void	key_press(t_keyboard *key, int keycode)
{
	if (keycode == KEY_UP)
		key->up = 1;
	if (keycode == KEY_DOWN)
		key->down = 1;
	if (keycode == KEY_LEFT)
	{
		key->right = 0;
		key->left = 1;
	}
	if (keycode == KEY_RIGHT)
	{
		key->left = 0;
		key->right = 1;
	}
}

void	key_release(t_keyboard *key, int keycode)
{
	if (keycode == KEY_UP)
		key->up = 0;
	if (keycode == KEY_DOWN)
		key->down = 0;
	if (keycode == KEY_LEFT)
		key->left = 0;
	if (keycode == KEY_RIGHT)
		key->right = 0;
}

void	key_up_down(t_env *e)
{
	if (e->key.up)
	{
		if (e->map->wall[(int)(e->player.pos->y + e->player.dir->y
			* MOVESPEED * 1.5)][(int)(e->player.pos->x)] == 0)
			e->player.pos->y += e->player.dir->y * MOVESPEED;
		if (e->map->wall[(int)(e->player.pos->y)][(int)(e->player.pos->x
			+ e->player.dir->x * MOVESPEED * 1.5)] == 0)
			e->player.pos->x += e->player.dir->x * MOVESPEED;
	}
	if (e->key.down)
	{
		if (e->map->wall[(int)(e->player.pos->y - e->player.dir->y
			* MOVESPEED * 1.5)][(int)(e->player.pos->x)] == 0)
			e->player.pos->y -= e->player.dir->y * MOVESPEED;
		if (e->map->wall[(int)(e->player.pos->y)][(int)(e->player.pos->x
			- e->player.dir->x * MOVESPEED * 1.5)] == 0)
			e->player.pos->x -= e->player.dir->x * MOVESPEED;
	}
}

void	key_left_right(t_env *e)
{
	double olddirx;
	double oldplanex;

	olddirx = e->player.dir->x;
	oldplanex = e->player.plane->x;
	if (e->key.left)
	{
		e->player.dir->x = e->player.dir->x * C_R - e->player.dir->y * S_R;
		e->player.dir->y = olddirx * S_R + e->player.dir->y * C_R;
		e->player.plane->x = e->player.plane->x
			* C_R - e->player.plane->y * S_R;
		e->player.plane->y = oldplanex * S_R + e->player.plane->y * C_R;
	}
	if (e->key.right)
	{
		e->player.dir->x = e->player.dir->x * CR - e->player.dir->y * SR;
		e->player.dir->y = olddirx * SR + e->player.dir->y * CR;
		e->player.plane->x = e->player.plane->x
			* CR - e->player.plane->y * SR;
		e->player.plane->y = oldplanex * SR + e->player.plane->y * CR;
	}
}
