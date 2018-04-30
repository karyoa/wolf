/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:58:19 by yokartou          #+#    #+#             */
/*   Updated: 2017/10/16 11:57:33 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	s2 = (char*)malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (0);
	i = 0;
	while (s1[i])
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}
