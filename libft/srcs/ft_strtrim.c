/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:03:35 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/23 12:40:40 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	size_t				start;
	size_t				end;
	size_t				len;
	char				*str;

	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
	{
		start++;
		if (s[start] == '\0')
			return (ft_strnew(0));
	}
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	len = end - start + 1;
	str = ft_strsub(s, start, len);
	return (str);
}
