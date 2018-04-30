/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:08:34 by yokartou          #+#    #+#             */
/*   Updated: 2018/03/05 10:11:10 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstnew2(char const *content, size_t filed)
{
	t_gnl	*tmp;

	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(tmp->content = ft_strnew(ft_strlen((char *)content))))
		return (NULL);
	ft_strcpy(tmp->content, (char *)content);
	tmp->head = tmp->content;
	tmp->filed = filed;
	tmp->next = NULL;
	return (tmp);
}
