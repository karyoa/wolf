/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:34 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/04 08:07:48 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pxl(t_env *e, int x, int y, int color)
{
	int		i;

	if ((x > 0 && x < e->width) && (y > 0 && y < e->height))
	{
		i = e->width * y * 4 + x * 4;
		e->mlx.pxl[i] = color;
		e->mlx.pxl[i + 1] = color >> 8;
		e->mlx.pxl[i + 2] = color >> 16;
	}
}

int		getcolor(t_img *img, int x, int y, int fade)
{
	int	color;
	int	c;

	fade /= 8;
	c = (y * img->width + x) * 4;
	color = img->buffer[c];
	if (color == -120 && img->buffer[c + 1] == 0 && img->buffer[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += img->buffer[c + 1] * 256;
	color += img->buffer[c + 2] * 256 * 256;
	return (color);
}
