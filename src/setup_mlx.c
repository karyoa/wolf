/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:02:24 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/02 19:03:40 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_load_text(t_env *e)
{
	int		width;
	int		height;

	e->wall[0] = mlx_xpm_file_to_image(e->mlx.mlx, TEXT_W, &width, &height);
	e->wall[1] = mlx_xpm_file_to_image(e->mlx.mlx, TEXT_E, &width, &height);
	e->wall[2] = mlx_xpm_file_to_image(e->mlx.mlx, TEXT_N, &width, &height);
	e->wall[3] = mlx_xpm_file_to_image(e->mlx.mlx, TEXT_S, &width, &height);
}

static int	ft_loop_hook(t_env *e)
{
	key_up_down(e);
	key_left_right(e);
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img,
	&(e->mlx.bpp), &(e->mlx.s_line), &(e->mlx.endian));
	ft_raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	return (0);
}

static void	ft_init_var(t_env *e)
{
	e->key.up = 0;
	e->key.down = 0;
	e->key.left = 0;
	e->key.right = 0;
	e->key.sleft = 0;
	e->key.sright = 0;
	e->mlx.bpp = 0;
	e->mlx.s_line = 0;
	e->mlx.endian = 0;
}

void		setup_mlx(t_env *e)
{
	ft_init_var(e);
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "Wolf3d");
	ft_load_text(e);
	mlx_hook(e->mlx.win, 2, 1, key_press_hook, e);
	mlx_hook(e->mlx.win, 3, 1, key_release_hook, e);
	mlx_loop_hook(e->mlx.mlx, ft_loop_hook, e);
	mlx_loop(e->mlx.mlx);
}
