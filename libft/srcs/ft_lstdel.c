/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:07:47 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/26 13:07:20 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*lst;
	t_list		*tmp;

	lst = *alst;
	while (lst)
	{
		tmp = lst->next;
		del(lst, lst->content_size);
		lst = tmp;
	}
	*alst = NULL;
}
