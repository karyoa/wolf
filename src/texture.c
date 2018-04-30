#include "wolf3d.h"

void	texture_load(t_env *e)
{
	int		width;
	int		height;

	e->wall[0] = mlx_xpm_file_to_image(e->mlx.mlx,
			TEXTURE_WEST, &width, &height);
	e->wall[1] = mlx_xpm_file_to_image(e->mlx.mlx,
			TEXTURE_EAST, &width, &height);
	e->wall[2] = mlx_xpm_file_to_image(e->mlx.mlx,
			TEXTURE_NORTH, &width, &height);
	e->wall[3] = mlx_xpm_file_to_image(e->mlx.mlx,
			TEXTURE_SOUTH, &width, &height);
}
