/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:53:54 by yokartou          #+#    #+#             */
/*   Updated: 2017/10/11 14:55:10 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*d;

	i = 0;
	if (!s)
		return (0);
	d = (char*)malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (0);
	while (i < len && s[start])
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}
