/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:48:27 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/24 16:47:32 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_filltab(char *str, int n, int len)
{
	int			sign;

	sign = 1;
	str[len] = '\0';
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	while (--len >= 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		if (sign == -1)
			str[0] = '-';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			nb;

	if (n == 0)
		return (ft_strdup("0"));
	len = (n < 0) ? 1 : 0;
	nb = (n < 0) ? -n : n;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_filltab(str, n, len));
}
