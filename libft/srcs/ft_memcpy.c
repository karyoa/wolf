/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:06:46 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/23 14:46:15 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, void const *src, size_t n)
{
	char	*str1;
	char	*str2;

	if (n == 0 || dest == src)
		return (dest);
	str1 = (char *)dest;
	str2 = (char *)src;
	while (--n)
		*str1++ = *str2++;
	*str1 = *str2;
	return (dest);
}
