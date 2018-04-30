/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:17:36 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/23 17:44:13 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(char const *s, int c)
{
	size_t			i;
	char			*str;

	str = (char *)s;
	if (c == 0)
		return (str + ft_strlen(s));
	if (s[0] == '\0')
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	if (str[0] == c)
		return (&str[0]);
	return (NULL);
}
