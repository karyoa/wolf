/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:00:23 by yokartou          #+#    #+#             */
/*   Updated: 2017/10/11 15:01:03 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_2strlen(char const *s1, char const *s2)
{
	int i;
	int n;

	i = 0;
	while (s1[i])
		i++;
	n = i;
	i = 0;
	while (s2[i])
		i++;
	n = n + i;
	return (n);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	d = (char*)malloc(sizeof(char) * (ft_2strlen(s1, s2) + 1));
	if (d == NULL)
		return (0);
	while (s1[i])
		d[j++] = s1[i++];
	i = 0;
	while (s2[i])
		d[j++] = s2[i++];
	d[j] = '\0';
	return (d);
}
