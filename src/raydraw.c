#include "wolf3d.h"

void	ft_ray_limit(t_env *e)
{
	e->lineheight = abs((int)(HEIGHT / e->ray.perpwalldist));
	e->drawstart = -e->lineheight / 2 + HEIGHT / 2;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = e->lineheight / 2 + HEIGHT / 2;
	if (e->drawend >= HEIGHT)
		e->drawend = HEIGHT - 1;
	if (e->ray.hit_side == 1)
		e->wallx = e->ray.pos.x + ((e->ray.map.y - e->ray.pos.y +
		(1 - e->ray.step.y) / 2) / e->ray.dir.y) * e->ray.dir.x;
	else
		e->wallx = e->ray.pos.y + ((e->ray.map.x - e->ray.pos.x +
		(1 - e->ray.step.x) / 2) / e->ray.dir.x) * e->ray.dir.y;
	e->wallx -= floor(e->wallx);
	e->tex.x = (int)(e->wallx * (double)64);
	e->tex.x = 64 - e->tex.x - 1;
	e->y = 0;
}

int		ft_wall_side(t_env *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (0);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
			(e->ray.step.x == 1 && e->ray.step.y == 1))
				return (1);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (2);
	return (3);
}

void	ft_draw_wall(t_env *e)
{
	int	d;
	int	wall;

	wall = e->map.wall[(int)e->ray.map.y][(int)e->ray.map.x];
	while (e->y < e->drawend)
	{
		d = e->y * 256 - HEIGHT * 128 + e->lineheight * 128;
		e->tex.y = ((d * 64) / e->lineheight) / 256;
		put_pxl(e, e->x, e->y, getcolor(e->wall[ft_wall_side(e)],
					e->tex.x, e->tex.y, e->ray.perpwalldist));
		e->y++;
	}
}

// void 	ft_draw_floor(t_env *e)
// {
// 	if (e->ray.hit_side == 0 && e->ray.dir.x > 0)
// 	{
//     	e->floor.x = e->player.pos.x;
//         e->floor.y = e->player.pos.y + e->wallx;
//     }
//     else if (e->ray.hit_side == 0 && e->ray.dir.x < 0)
//     {
//         e->floor.x = e->player.pos.x + 1.0;
//         e->floor.y = e->player.pos.y + e->wallx;
//     }
//     else if (e->ray.hit_side == 1 && e->ray.dir.y > 0)
//     {
//         e->floor.x = e->player.pos.x + e->wallx;
//         e->floor.y = e->player.pos.y;
//     }
//     else
//     {
//         e->floor.x = e->player.pos.x + e->wallx;
//         e->floor.y = e->player.pos.y + 1.0;
//     }
// 	e->walldist = e->ray.perpwalldist;
//     e->playerdist = 0.0;
// 	while (e->y < HEIGHT - e->y)
//     {
//         e->currentdist = HEIGHT / (2.0 * e->y - HEIGHT);
//         e->weight = (e->currentdist - e->playerdist) / (e->walldist - e->playerdist);
//         e->curfloor.x = e->weight * e->floor.x + (1.0 - e->weight) * e->player.pos.x;
//         e->curfloor.y = e->weight * e->floor.y + (1.0 - e->weight) * e->player.pos.y;
//         e->floortex.x = (int)(e->curfloor.x * 64) % 64;
//         e->floortex.y = (int)(e->curfloor.y * 64) % 64;
// 		// put_pxl(e, e->x, HEIGHT - e->y, getcolor(e->wall[0], e->floortex.x, e->floortex.y, 0));
// 		put_pxl(e, e->x, e->y, getcolor(e->wall[0], e->floortex.x, e->floortex.y, 0));
//         // buffer[y][x] = (texture[3][texWidth * floorTexY + floorTexX] >> 1) & 8355711;
//         // buffer[h - y][x] = texture[6][texWidth * floorTexY + floorTexX];
// 		e->y++;
// 	}
// }

void	ft_draw(t_env *e, int x)
{
	ft_ray_limit(e);
	e->x = x;
	ft_draw_wall(e);
	// ft_draw_fl oor(e);
	while (e->y < HEIGHT + 1)
	{
		put_pxl(e, e->x, e->y, 0x252525);
		put_pxl(e, e->x, HEIGHT - e->y, 0xabcdef);
		e->y++;
	}
}
