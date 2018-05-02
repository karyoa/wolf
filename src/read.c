/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:47:10 by ojerroud          #+#    #+#             */
/*   Updated: 2018/05/02 19:01:41 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	read_map(t_env *e, int fd, char *line, char **tab)
{
	int		i;
	int		j;
	int		ret;

	e->map.wall = (int **)malloc(sizeof(int *) * e->map.height);
	i = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		(i >= e->map.height) ? ft_error("wrong map") : 0;
		e->map.wall[++i] = (int *)malloc(sizeof(int) * e->map.width);
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		j = -1;
		while (tab[++j])
		{
			(j >= e->map.width) ? ft_error("wrong map") : 0;
			e->map.wall[i][j] = ft_atoi(tab[j]);
			ft_strdel(&tab[j]);
		}
		(j != e->map.width) ? ft_error("wrong map") : 0;
		free(tab);
	}
	(i + 1 != e->map.height) ? ft_error("wrong map") : 0;
	(ret == -1) ? ft_error("gnl") : 0;
}

static void	read_first_line(t_env *e, int fd, char *line, char **tab)
{
	int		cpt;

	if (get_next_line(fd, &line) < 1)
		ft_error("file empty");
	tab = ft_strsplit(line, ' ');
	cpt = 0;
	while (tab[cpt])
		cpt++;
	if (cpt != 4)
		ft_error("wrong first line (4 int expected: width height posx posy)");
	ft_strdel(&line);
	e->map.width = ft_atoi(tab[0]);
	e->map.height = ft_atoi(tab[1]);
	e->player.pos.x = ft_atoi(tab[2]);
	e->player.pos.y = ft_atoi(tab[3]);
	e->player.dir.x = e->player.pos.x - 2;
	e->player.dir.y = e->player.pos.x - 1;
	(e->player.pos.x < 1) ? e->player.pos.x = 1 : 0;
	(e->player.pos.x > e->map.width) ? e->player.pos.x = e->map.width : 0;
	(e->player.pos.y < 1) ? e->player.pos.y = 1 : 0;
	(e->player.pos.y > e->map.height) ? e->player.pos.y = e->map.height : 0;
	e->i = -1;
	while (tab[++e->i])
		ft_strdel(&tab[e->i]);
	free(tab);
}

static void	read_lines(t_env *e, int fd)
{
	char	*line;
	char	**tab;

	line = NULL;
	tab = NULL;
	read_first_line(e, fd, line, tab);
	read_map(e, fd, line, tab);
	if (e->map.wall[(int)(e->player.pos.y - 0.5)][(int)(e->player.pos.x - 0.5)])
		ft_error("player pos");
}

void		read_params(t_env *e, char *input)
{
	int		fd;

	e->input = input;
	if ((fd = open(e->input, O_RDONLY)) == -1)
		ft_error("cannot open map");
	read_lines(e, fd);
	close(fd);
}
