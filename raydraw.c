#include "wolf3d.h"

void	ray_delimiter(t_env *e)
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

void	draw_ray_wall(t_env *e)
{
	int	d;
	int	wall;

	wall = e->map->wall[(int)e->ray.map.y][(int)e->ray.map.x];
	while (e->y < e->drawend)
	{
		d = e->y * 256 - HEIGHT * 128 + e->lineheight * 128;
		e->tex.y = ((d * 64) / e->lineheight) / 256;
		put_pxl(e, e->x, e->y, getcolor(e->wall[wall + 1],
					e->tex.x, e->tex.y, e->ray.perpwalldist));
		e->y++;
	}
}

void	draw_ray(t_env *e, int x)
{
	ray_delimiter(e);
	e->x = x;
	e->ray.zbuffer[x] = e->ray.perpwalldist;
	draw_ray_wall(e);
	while (e->y < HEIGHT)
	{
		put_pxl(e, e->x, e->y, 0x000000);
		put_pxl(e, e->x, HEIGHT - e->y, 0x000000);
		e->y++;
	}
}
