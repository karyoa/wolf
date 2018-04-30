/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:58:33 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/26 13:00:01 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*newlist;
	t_list		*lis;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlist = f(lst);
	lis = newlist;
	while (lst->next)
	{
		if (!(newlist->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		lst = lst->next;
		newlist->next = f(lst);
		newlist = newlist->next;
	}
	return (lis);
}
