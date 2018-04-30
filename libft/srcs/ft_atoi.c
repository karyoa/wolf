/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokartou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 14:20:01 by yokartou          #+#    #+#             */
/*   Updated: 2017/04/24 12:48:25 by yokartou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_epur(long long *i, long long *res, char const *nptr)
{
	while (nptr[*i] <= '9' && nptr[*i] >= '0')
	{
		*res = *res * 10 + (nptr[*i] - 48);
		(*i)++;
	}
}

int				ft_atoi(char const *nptr)
{
	long long		i;
	long long		sign;
	long long		res;

	i = 0;
	sign = 1;
	res = 0;
	while (!(nptr[i] <= '9' && nptr[i] >= '0'))
	{
		if ((nptr[i] == 45 || nptr[i] == 43) &&
				(nptr[i + 1] <= 57 && nptr[i + 1] >= 48))
		{
			if (nptr[i] == 45)
				sign = -1;
			i++;
		}
		else if ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
			i++;
		else
			return (res);
	}
	ft_epur(&i, &res, nptr);
	return (res * sign);
}
