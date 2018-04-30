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

void		setplane(t_env *e, double fov)
{
	double	fx;
	double	fy;
	double	px;
	double	py;

	fx = e->player.dir.x;
	fy = e->player.dir.y;
	px = (int)(fx * cos(d2r(90)) - fy * sin(d2r(90)));
	py = (int)(fx * sin(d2r(90)) + fy * cos(d2r(90)));
	e->player.plane = newcoord(fov * px, fov * py);
}

void	ft_error(char *error)
{
	ft_putstr(error);
	exit(0);
}

void	print_table(t_env e)
{
	int	i;
	int j;

	i = -1;
	while (++i < e.map.height)
	{
		j = -1;
		while (++j < e.map.width)
			printf("%d ", e.map.wall[i][j]);
		printf("\n");
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("Error Number Argument");
	read_params(&e, av[1]);
	setplane(&e, FOV);
	printf("x/y = [%d][%d]\npos = [%f][%f]\n", e.map.height, e.map.width, e.player.pos.x, e.player.pos.y);
	print_table(e);
	// while (1){}
	setup_mlx(&e);
	return (0);
}
