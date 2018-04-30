/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:45:37 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/23 17:39:44 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(char const *str, char const *to_find, size_t n)
{
	char		*s1;
	size_t		i;
	size_t		j;
	size_t		k;

	i = -1;
	s1 = (char *)str;
	if (to_find[0] == '\0')
		return (s1);
	while (s1[++i] && i < n)
	{
		j = 0;
		if (s1[i] == to_find[j])
		{
			k = i;
			while (to_find[j] && to_find[j] == s1[k] && k < n)
			{
				j++;
				k++;
			}
			if (to_find[j] == '\0')
				return (&s1[i]);
		}
	}
	return (NULL);
}
