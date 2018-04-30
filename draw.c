#include "wolf3d.h"

int		tchouin(int r, int g, int b)
{
	int	color;

	color = 256 * 256 * r;
	color += 256 * g;
	color += b;
	return (color);
}

void	put_pxl(t_env *e, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (e->mlx.s_line * y) + (x * (e->mlx.bpp / 8));
	e->mlx.pxl[i] = b;
	e->mlx.pxl[i + 1] = g;
	e->mlx.pxl[i + 2] = r;
}

int		getcolor(t_img *img, int x, int y, int fade)
{
	int	color;
	int	c;

	fade /= 8;
	c = (y * img->width + x) * 4;
	color = img->buffer[c];
	if (color == -120 && img->buffer[c + 1] == 0 && img->buffer[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += img->buffer[c + 1] * 256;
	color += img->buffer[c + 2] * 256 * 256;
	return (color);
}

void	drawbyside(t_env *e, int x, int y)
{
	if (e->ray.dir.y > 0 && e->ray.hit_side)
		put_pxl(e, x, y, 0xFF0000);
	if (e->ray.dir.y < 0 && e->ray.hit_side)
		put_pxl(e, x, y, 0x00FF00);
	if (e->ray.dir.x > 0 && e->ray.hit_side == 0)
		put_pxl(e, x, y, 0x0000FF);
	if (e->ray.dir.x < 0 && e->ray.hit_side == 0)
		put_pxl(e, x, y, 0xAA00BB);
}
