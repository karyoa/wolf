#include "wolf3d.h"

void 	ft_error(char *error)
{
	ft_putstr(error);
	exit(1);
}

int		main(int ac, char **av)
{
	t_map 		*map;
	t_player 	*player;

	if (ac != 2)
		ft_error("Error Number Argument");
	map = ft_open_file(av[1]);
	setup_mlx(player, map);
	return (0);
}
