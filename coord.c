#include "wolf3d.h"

t_dxy	*newcoord(double x, double y)
{
	t_dxy *ntm;

	ntm = malloc(sizeof(t_dxy));
	ntm->x = x;
	ntm->y = y;
	return (ntm);
}
