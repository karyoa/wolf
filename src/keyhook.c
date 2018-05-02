/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:52:24 by yokartou          #+#    #+#             */
/*   Updated: 2018/05/02 18:54:44 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_press(t_keyboard *key, int keycode)
{
	if (keycode == KEY_UP)
		key->up = 1;
	if (keycode == KEY_DOWN)
		key->down = 1;
	if (keycode == KEY_LEFT)
	{
		key->right = 0;
		key->left = 1;
	}
	if (keycode == KEY_RIGHT)
	{
		key->left = 0;
		key->right = 1;
	}
}

void	key_release(t_keyboard *key, int keycode)
{
	if (keycode == KEY_UP)
		key->up = 0;
	if (keycode == KEY_DOWN)
		key->down = 0;
	if (keycode == KEY_LEFT)
		key->left = 0;
	if (keycode == KEY_RIGHT)
		key->right = 0;
}

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
