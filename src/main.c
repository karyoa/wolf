/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:21 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/03 10:30:55 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_set_plane(t_env *e)
{
	double	fx;
	double	fy;
	double	px;
	double	py;

	fx = e->player.dir.x;
	fy = e->player.dir.y;
	px = (int)(fx * cos(M_PI * 90 / 180) - fy * sin(M_PI * 90 / 180));
	py = (int)(fx * sin(M_PI * 90 / 180) + fy * cos(M_PI * 90 / 180));
	e->player.plane.x = FOV * px;
	e->player.plane.y = FOV * py;
}

static void	ft_check_map(t_env *e)
{
	int	x;
	int	y;

	x = -1;
	while (++x < e->map.height)
	{
		y = -1;
		while (++y < e->map.width)
		{
			if (x == 0 || x == e->map.height - 1)
			{
				if (e->map.wall[x][y] == 0)
					ft_error("Error Wall Map");
			}
			if (y == 0 || y == e->map.width - 1)
			{
				if (e->map.wall[x][y] == 0)
					ft_error("Error Wall Map");
			}
		}
	}
}

static void	ft_check_pos(t_env *e)
{
	if (e->player.pos.x == 1 || e->player.pos.y == 1
		|| e->player.pos.y >= e->map.height - 1
		|| e->player.pos.x >= e->map.width - 1)
		ft_error("Error Spawn Pos");
	if (e->map.wall[(int)e->player.pos.x][(int)e->player.pos.y] == 1)
		ft_error("Error Spawn In Wall");
}

void		ft_error(char *error)
{
	ft_putstr(error);
	exit(1);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("Error Number Argument");
	read_params(&e, av[1]);
	ft_check_map(&e);
	ft_check_pos(&e);
	ft_set_plane(&e);
	setup_mlx(&e);
	return (0);
}
