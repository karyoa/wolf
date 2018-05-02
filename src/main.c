/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:21 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/02 18:57:49 by yokartou         ###   ########.fr       */
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

void		ft_error(char *error)
{
	ft_putstr(error);
	exit(0);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("Error Number Argument");
	read_params(&e, av[1]);
	ft_set_plane(&e);
	setup_mlx(&e);
	return (0);
}
