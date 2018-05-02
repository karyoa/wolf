#include "wolf3d.h"

void		setplane(t_env *e)
{
	double	fx;
	double	fy;
	double	px;
	double	py;

	fx = e->player.dir.x;
	fy = e->player.dir.y;
	px = (int)(fx * cos(M_PI * 90 / 180) - fy * sin(M_PI * 90 / 180));
	py = (int)(fx * sin(M_PI * 90 / 180) + fy * cos(M_PI * 90 / 180));
	e->player.plane.x = FOV * px;
	e->player.plane.y = FOV * py;
}

void	ft_error(char *error)
{
	ft_putstr(error);
	exit(0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("Error Number Argument");
	read_params(&e, av[1]);
	setplane(&e);
	setup_mlx(&e);
	return (0);
}
