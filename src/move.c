/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:26 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/02 18:53:16 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_up_down(t_env *e)
{
	if (e->key.up)
	{
		if (e->map.wall[(int)(e->player.pos.y + e->player.dir.y
			* MOVESPEED * 1.5)][(int)(e->player.pos.x)] == 0)
			e->player.pos.y += e->player.dir.y * MOVESPEED;
		if (e->map.wall[(int)(e->player.pos.y)][(int)(e->player.pos.x
			+ e->player.dir.x * MOVESPEED * 1.5)] == 0)
			e->player.pos.x += e->player.dir.x * MOVESPEED;
	}
	if (e->key.down)
	{
		if (e->map.wall[(int)(e->player.pos.y - e->player.dir.y
			* MOVESPEED * 1.5)][(int)(e->player.pos.x)] == 0)
			e->player.pos.y -= e->player.dir.y * MOVESPEED;
		if (e->map.wall[(int)(e->player.pos.y)][(int)(e->player.pos.x
			- e->player.dir.x * MOVESPEED * 1.5)] == 0)
			e->player.pos.x -= e->player.dir.x * MOVESPEED;
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
		e->player.dir.x = e->player.dir.x * C_R - e->player.dir.y * S_R;
		e->player.dir.y = olddirx * S_R + e->player.dir.y * C_R;
		e->player.plane.x = e->player.plane.x
			* C_R - e->player.plane.y * S_R;
		e->player.plane.y = oldplanex * S_R + e->player.plane.y * C_R;
	}
	if (e->key.right)
	{
		e->player.dir.x = e->player.dir.x * CR - e->player.dir.y * SR;
		e->player.dir.y = olddirx * SR + e->player.dir.y * CR;
		e->player.plane.x = e->player.plane.x
			* CR - e->player.plane.y * SR;
		e->player.plane.y = oldplanex * SR + e->player.plane.y * CR;
	}
}
