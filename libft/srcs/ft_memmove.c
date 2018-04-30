/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:32:08 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/23 13:45:34 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, void const *src, size_t n)
{
	char		*str1;
	char		*str2;
	size_t		i;

	i = -1;
	str1 = (char*)src;
	str2 = (char*)dest;
	if (str1 < str2)
		while ((int)(--n) >= 0)
			*(str2 + n) = *(str1 + n);
	else
		while (++i < n)
			*(str2 + i) = *(str1 + i);
	return (dest);
}
