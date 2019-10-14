/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:16 by yokartou          #+#    #+#             */
/*   Updated: 2019/10/14 11:23:09 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_ray_limit(t_env *e)
{
	//	calculate height of line to draw on screen
	e->lineheight = abs((int)(e->height / e->ray.perpwalldist));
	//	calculate lowest and highest pixel to fill in current stripe
	e->drawstart = -e->lineheight / 2 + e->height / 2;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = e->lineheight / 2 + e->height / 2;
	if (e->drawend >= e->height)
		e->drawend = e->height - 1;
	//	calulate value of wallx
	if (e->ray.hit_side == 1)
		e->wallx = e->ray.pos.x + ((e->ray.map.y - e->ray.pos.y + (1 - e->ray.step.y) / 2) / e->ray.dir.y) * e->ray.dir.x;
	else
		e->wallx = e->ray.pos.y + ((e->ray.map.x - e->ray.pos.x + (1 - e->ray.step.x) / 2) / e->ray.dir.x) * e->ray.dir.y;
	e->wallx -= floor(e->wallx);
	e->tex.x = (int)(e->wallx * (double)64);
	e->tex.x = 64 - e->tex.x - 1;
	e->y = 0;
}

static int	ft_wall_side(t_env *e)
{
	//	calculate which side has been hit by ray
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) || (e->ray.step.x == 1 && e->ray.step.y == -1))
			return (0);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) || (e->ray.step.x == 1 && e->ray.step.y == 1))
			return (1);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) || (e->ray.step.x == -1 && e->ray.step.y == 1))
		return (2);
	return (3);
}

static void	ft_draw_wall(t_env *e)
{
	int	d;
	int	wall;

	wall = e->map.wall[(int)e->ray.map.y][(int)e->ray.map.x];
	while (e->y < e->drawend)
	{
		//	256 and 128 factors to avoid floats
		d = e->y * 256 - e->height * 128 + e->lineheight * 128;
		e->tex.y = ((d * 64) / e->lineheight) / 256;
		put_pxl(e, e->x, e->y, getcolor(e->wall[ft_wall_side(e)], e->tex.x, e->tex.y, e->ray.perpwalldist));
		e->y++;
	}
}

static void	ft_draw_floor(t_env *e)
{
	if (e->ray.hit_side == 0 && e->ray.dir.x > 0)
	{
		e->floor.x = e->ray.map.x;
		e->floor.y = e->ray.map.y + e->wallx;
	}
	else if (e->ray.hit_side == 0 && e->ray.dir.x < 0)
	{
		e->floor.x = e->ray.map.x + 1.0;
		e->floor.y = e->ray.map.y + e->wallx;
	}
	else if (e->ray.hit_side == 1 && e->ray.dir.y > 0)
	{
		e->floor.x = e->ray.map.x + e->wallx;
		e->floor.y = e->ray.map.y;
	}
	else
	{
		e->floor.x = e->ray.map.x + e->wallx;
		e->floor.y = e->ray.map.y + 1.0;
	}
	e->walldist = e->ray.perpwalldist;
	e->playerdist = 0.0;
}

void		ft_draw(t_env *e, int x)
{
	e->x = x;
	ft_ray_limit(e);
	ft_draw_wall(e);
	ft_draw_floor(e);
	while (e->y < e->height + 1)
	{
		e->currentdist = e->height / (2.0 * e->y - e->height);
		e->weight = (e->currentdist - e->playerdist) / (e->walldist - e->playerdist);
		e->curfloor.x = e->weight * e->floor.x + (1.0 - e->weight) * e->player.pos.x;
		e->curfloor.y = e->weight * e->floor.y + (1.0 - e->weight) * e->player.pos.y;
		e->floortex.x = (int)(e->curfloor.x * 64) % 64;
		e->floortex.y = (int)(e->curfloor.y * 64) % 64;
		put_pxl(e, e->x, e->y, getcolor(e->wall[4], e->floortex.x, e->floortex.y, 0));
		put_pxl(e, e->x, e->height - e->y, getcolor(e->wall[5], e->floortex.x, e->floortex.y, 0));
		e->y++;
	}
}
