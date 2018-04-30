#include "wolf3d.h"

void	texture_load(t_env *e)
{
	int		width;
	int		height;

	e->wall[0] = mlx_xpm_file_to_image(e->mlx.mlx,
			"texture/wall1h.xpm", &width, &height);
	e->wall[1] = mlx_xpm_file_to_image(e->mlx.mlx,
			"texture/wall2h.xpm", &width, &height);
	e->wall[2] = mlx_xpm_file_to_image(e->mlx.mlx,
			"texture/wall3h.xpm", &width, &height);
	e->wall[3] = mlx_xpm_file_to_image(e->mlx.mlx,
			"texture/wall4h.xpm", &width, &height);
	e->wall[4] = mlx_xpm_file_to_image(e->mlx.mlx,
			"texture/wall4h.xpm", &width, &height);
}
