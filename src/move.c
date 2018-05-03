/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:26 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/03 11:17:40 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_up_down(t_env *e)
{
	if (e->key.up)
	{
		if (e->map.wall[(int)(e->player.pos.y + e->player.dir.y
			* 0.1 * 1.5)][(int)(e->player.pos.x)] == 0)
			e->player.pos.y += e->player.dir.y * 0.1;
		if (e->map.wall[(int)(e->player.pos.y)][(int)(e->player.pos.x
			+ e->player.dir.x * 0.1 * 1.5)] == 0)
			e->player.pos.x += e->player.dir.x * 0.1;
	}
	if (e->key.down)
	{
		if (e->map.wall[(int)(e->player.pos.y - e->player.dir.y
			* 0.1 * 1.5)][(int)(e->player.pos.x)] == 0)
			e->player.pos.y -= e->player.dir.y * 0.1;
		if (e->map.wall[(int)(e->player.pos.y)][(int)(e->player.pos.x
			- e->player.dir.x * 0.1 * 1.5)] == 0)
			e->player.pos.x -= e->player.dir.x * 0.1;
	}
}

void	key_left_right(t_env *e)
{
	double olddirx;
	double oldplanex;

	olddirx = e->player.dir.x;
	oldplanex = e->player.plane.x;
	if (e->key.left)
	{
		e->player.dir.x = e->player.dir.x * cos(-0.1)
		- e->player.dir.y * sin(-0.1);
		e->player.dir.y = olddirx * sin(-0.1) + e->player.dir.y * cos(-0.1);
		e->player.plane.x = e->player.plane.x
			* cos(-0.1) - e->player.plane.y * sin(-0.1);
		e->player.plane.y = oldplanex * sin(-0.1)
		+ e->player.plane.y * cos(-0.1);
	}
	if (e->key.right)
	{
		e->player.dir.x = e->player.dir.x * cos(0.1)
		- e->player.dir.y * sin(0.1);
		e->player.dir.y = olddirx * sin(0.1) + e->player.dir.y * cos(0.1);
		e->player.plane.x = e->player.plane.x
			* cos(0.1) - e->player.plane.y * sin(0.1);
		e->player.plane.y = oldplanex * sin(0.1) + e->player.plane.y * cos(0.1);
	}
}
