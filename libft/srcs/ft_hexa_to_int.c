/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:28:08 by ojerroud          #+#    #+#             */
/*   Updated: 2018/01/11 17:28:16 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	puissance(int nbr, int puiss)
{
	int	i;
	int res;

	if (puiss == 0)
		return (1);
	if (puiss == 1)
		return (nbr);
	i = 1;
	res = nbr;
	while (++i <= puiss)
		res *= nbr;
	return (res);
}

int			ft_hexa_to_int(char *str)
{
	int nbr;
	int i;
	int	puiss;

	nbr = 0;
	puiss = -1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr += ((str[i--] - 48) * puissance(16, ++puiss));
		else if (str[i] >= 'a' && str[i] <= 'f')
			nbr += ((str[i--] - 87) * puissance(16, ++puiss));
		else if (str[i] >= 'A' && str[i] <= 'F')
			nbr += ((str[i--] - 55) * puissance(16, ++puiss));
		else
		{
			ft_putstr("error: hexa other than : 0123456789abcdefABCDEF (");
			ft_putstr(str);
			ft_putendl(")");
			exit(0);
		}
	}
	return (nbr);
}
