#include "wolf3d.h"

// t_list	*read_file(char *filepath)
// {
// 	t_list	*list;
// 	t_list	*l;
// 	char	*line;
// 	int		fd;
//
// 	list = NULL;
// 	if ((fd = open(filepath, O_RDONLY)))
// 	{
// 		while (get_next_line(fd, &line) > 0)
// 		{
// 			l = ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1);
// 			ft_lstadd(&list, l);
// 			free(line);
// 		}
// 		if (list)
// 			return (list);
// 	}
// 	ft_putstr("no map or not readable");
// 	exit(EXIT_FAILURE);
// }

static void 	ft_read_map_info(t_map *tmp, int fd)
{
	char	**line_split;
	char	*line;
	int 	i;

	i = 0;
	if (get_next_line(fd, &line) < 1)
		ft_error("Error Map");
	line_split = ft_strsplit(line, ' ');
	while (line_split[i] != '\0')
		i++;
	if (i != 4)
		ft_error("Error Map File Info Invalid Number Data");
	e->map->x = ft_atoi(line_split[0]);
	e->map->y = ft_atoi(line_split[1]);
	e->player.pos->x = ft_atoi(line_split[2]);
	e->player.pos->y = ft_atoi(line_split[3]);
	if (e->map->x < 0 || e->map->y < 0 || e->player.pos->x < 0 ||
	e->player.pos->y < 0 || e->player.pos->x >= e->map->x ||
	e->player.pos->y >= e->map->y)
		ft_error("Error Map File Info Invalid Data");
}

static void 	ft_read_line(t_map *tmp, int **map, char *line, int y)
{
	char	**line_split;
	int		x;

	x = -1;
	if (y >= e->map->y)
		ft_error("Error Map File Info Invalid Height");
	line_split = ft_strsplit(line, ' ');
	if (!(map[y] = (int *)malloc(sizeof(int *) * e->map->x)))
		ft_error("Error Malloc");
	while (line_split[++x] != '\0')
	{
		if (!(line_split[x][0] >= '0' && line_split[x][0] <= '9'
	&& ft_atoi(line_split[x]) >= 0 && x < e->map->x))
			ft_error("Error Map File Invalid Data");
		map[y][x] = ft_atoi(line_split[x]);
		if ((x == 0 || x == e->map->x - 1 || y == 0 || y == e->map->y - 1) && map[y][x] == 0)
			ft_error("Error Map File Invalid Data");
	}
	if (x != e->map->x)
		ft_error("Error Map File Info Invalid Width");
}

static void 	ft_read_file(t_map *tmp, int fd)
{
	char	*line;
	int 	**map;
	int 	y;

	y = -1;
	ft_read_map_info(e, fd);
	if (!(map = (int **)malloc(sizeof(int *) * e->map->y)))
		ft_error("Error Malloc");
	while (get_next_line(fd, &line) == 1)
		ft_read_line(e, map, line, ++y);
	if (map[(int)e->player.pos->x][(int)e->player.pos->y] != 0)
		ft_error("Error Map File First Line Invalid Spawn");
	return (map);
}

void		ft_open_file(char *filepath)
{
	t_map	tmp;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd > 0)
		tmp = ft_read_file(map, fd);
	close(fd);
	return (map);
}
