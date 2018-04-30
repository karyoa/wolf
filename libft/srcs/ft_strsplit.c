/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:25:19 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/26 12:56:55 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	int		i;
	int		j;
	int		res;

	i = -1;
	res = 0;
	while (s[++i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			if (j == 0)
			{
				j = 1;
				i++;
				res++;
			}
			else
				i++;
		}
	}
	return (res);
}

static int		ft_len(char const *s, int j, char c)
{
	int		i;

	i = 0;
	while (s[j] && s[j] != c)
	{
		i++;
		j++;
	}
	return (i);
}

static char		*ft_cpy(char *dest, char const *s, int j, char c)
{
	int		i;
	int		size;

	i = 0;
	size = ft_len(s, j, c);
	while (i < size)
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		words;
	int		i;
	char	**dest;

	if (s == NULL)
		return (NULL);
	words = ft_words(s, c);
	j = 0;
	i = 0;
	dest = (char**)malloc(sizeof(char*) * (words + 1));
	if (dest == NULL)
		return (NULL);
	while (s[j] && i < words)
	{
		while (s[j] == c)
			j++;
		dest[i] = (char*)malloc(sizeof(char) * (ft_len(s, j, c) + 1));
		ft_cpy(dest[i], s, j, c);
		j = j + ft_len(s, j, c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
