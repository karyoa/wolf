#include "wolf3d.h"

void	rayinit(t_env *e, int x)
{
	e->ray.cam = 2 * x / (double)(WIDTH) - 1;
	e->ray.pos.x = e->player.pos->x;
	e->ray.pos.y = e->player.pos->y;
	e->ray.dir.x = e->player.dir->x + e->player.plane->x * e->ray.cam;
	e->ray.dir.y = e->player.dir->y + e->player.plane->y * e->ray.cam;
	e->ray.map.x = (int)e->ray.pos.x;
	e->ray.map.y = (int)e->ray.pos.y;
	e->ray.delta.x = sqrt(1 + (e->ray.dir.y * e->ray.dir.y)
			/ (e->ray.dir.x * e->ray.dir.x));
	e->ray.delta.y = sqrt(1 + (e->ray.dir.x * e->ray.dir.x)
			/ (e->ray.dir.y * e->ray.dir.y));
}

void	rayfindside(t_env *e)
{
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

void	raydda(t_env *e)
{
	while (e->ray.hit == 0)
	{
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
		if (e->map->wall[(int)e->ray.map.y][(int)e->ray.map.x] > 0)
			e->ray.hit = 1;
	}
}

void	raydist(t_env *e)
{
	if (e->ray.hit_side == 0)
		e->ray.perpwalldist = fabs(
				(e->ray.map.x - e->ray.pos.x + (1 - e->ray.step.x) / 2) / e->ray.dir.x);
	else
		e->ray.perpwalldist = fabs(
				(e->ray.map.y - e->ray.pos.y + (1 - e->ray.step.y) / 2) / e->ray.dir.y);
}

void	raycast(t_env *e)
{
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		rayinit(e, x);
		e->ray.hit = 0;
		rayfindside(e);
		raydda(e);
		raydist(e);
		draw_ray(e, x);
		x++;
	}
}
