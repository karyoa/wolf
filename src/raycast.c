/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:19 by yokartou          #+#    #+#             */
/*   Updated: 2019/10/14 11:41:26 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_ray_init(t_env *e, int x)
{
	e->ray.pos.x = e->player.pos.x;
	e->ray.pos.y = e->player.pos.y;
	//	calculate ray position and direction
	//	x coordinate in camera space
	e->ray.cam = 2 * x / (double)(e->width) - 1;
	e->ray.dir.x = e->player.dir.x + e->player.plane.x * e->ray.cam;
	e->ray.dir.y = e->player.dir.y + e->player.plane.y * e->ray.cam;
	//	which box of the map we're in
	e->ray.map.x = (int)e->ray.pos.x;
	e->ray.map.y = (int)e->ray.pos.y;
	//	length of ray from one x or y-side to next x or y-side
	e->ray.delta.x = sqrt(1 + (e->ray.dir.y * e->ray.dir.y)
			/ (e->ray.dir.x * e->ray.dir.x));
	e->ray.delta.y = sqrt(1 + (e->ray.dir.x * e->ray.dir.x)
			/ (e->ray.dir.y * e->ray.dir.y));
}

static void	ft_ray_find_side(t_env *e)
{
	//	what direction to step in x or y direction (+1 or -1)

	//	calculate ray.step.x and initial ray.dist.x
	if (e->ray.dir.x < 0)
	{
		e->ray.step.x = -1;
		e->ray.dist.x = (e->ray.pos.x - e->ray.map.x) * e->ray.delta.x;
	}
	else
	{
		e->ray.step.x = 1;
		e->ray.dist.x = (e->ray.map.x + 1.0 - e->ray.pos.x) * e->ray.delta.x;
	}
	if (e->ray.dir.y < 0)
	{
		e->ray.step.y = -1;
		e->ray.dist.y = (e->ray.pos.y - e->ray.map.y) * e->ray.delta.y;
	}
	else
	{
		e->ray.step.y = 1;
		e->ray.dist.y = (e->ray.map.y + 1.0 - e->ray.pos.y) * e->ray.delta.y;
	}
}

static void	ft_ray_dda(t_env *e)
{
	//	ray.hit was there a wall hit?
	while (e->ray.hit == 0)
	{
		//	jump to next map square, or in x direction, or in y direction
		//	ray.hit_side was a NS or a EW wall hit?
		if (e->ray.dist.x < e->ray.dist.y)
		{
			e->ray.dist.x += e->ray.delta.x;
			e->ray.map.x += e->ray.step.x;
			e->ray.hit_side = 0;
		}
		else
		{
			e->ray.dist.y += e->ray.delta.y;
			e->ray.map.y += e->ray.step.y;
			e->ray.hit_side = 1;
		}
		if (e->map.wall[(int)e->ray.map.y][(int)e->ray.map.x] > 0)
			e->ray.hit = 1;
	}
}

static void	ft_ray_dist(t_env *e)
{
	//	calculate distance of perpendicular ray
	if (e->ray.hit_side == 0)
		e->ray.perpwalldist = fabs((e->ray.map.x - e->ray.pos.x + (1 - e->ray.step.x) / 2) / e->ray.dir.x);
	else
		e->ray.perpwalldist = fabs((e->ray.map.y - e->ray.pos.y + (1 - e->ray.step.y) / 2)/ e->ray.dir.y);
}

void		ft_raycasting(t_env *e)
{
	int			x;

	x = 0;
	while (x < e->width)
	{
		ft_ray_init(e, x);
		e->ray.hit = 0;
		ft_ray_find_side(e);
		ft_ray_dda(e);
		ft_ray_dist(e);
		ft_draw(e, x);
		x++;
	}
}
