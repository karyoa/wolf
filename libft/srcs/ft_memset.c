/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 15:01:39 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/17 14:00:35 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	if (n == 0)
		return (s);
	str = (unsigned char *)s;
	while (n--)
	{
		*str = (unsigned char)c;
		if (n)
			str++;
	}
	return (s);
}
