#include "wolf3d.h"

int		key_press_hook(int keycode, t_env *e)
{
	key_press(&e->key, keycode);
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int		key_release_hook(int keycode, t_env *e)
{
	key_release(&e->key, keycode);
	return (0);
}

int		expose_hook(t_env *e)
{
	if (e)
	{}
	// render(e);
	return (0);
}
