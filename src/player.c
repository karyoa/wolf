#include "wolf3d.h"

t_dxy	newcoord(double x, double y)
{
	t_dxy ntm;

	ntm.x = x;
	ntm.y = y;
	return (ntm);
}

double		d2r(double d)
{
	return (M_PI * d / 180);
}

void		setplane(t_player *p, double fov)
{
	double	fx;
	double	fy;
	double	px;
	double	py;

	fx = p->dir.x;
	fy = p->dir.y;
	px = (int)(fx * cos(d2r(90)) - fy * sin(d2r(90)));
	py = (int)(fx * sin(d2r(90)) + fy * cos(d2r(90)));
	p->plane = newcoord(fov * px, fov * py);
}

t_player	*newplayer(double x, double y)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->pos = newcoord(x, y);
	player->dir = newcoord(0, 1);
	setplane(player, 0.66);
	return (player);
}
