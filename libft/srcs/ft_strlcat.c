/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:15:29 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/23 16:20:21 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		len;
	size_t		lendest;

	lendest = ft_strlen(dest);
	i = 0;
	j = 0;
	len = (ft_strlen(src));
	if (n <= ft_strlen(dest))
	{
		len = len + n;
		return (len);
	}
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < (n - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (lendest + ft_strlen(src));
}
