/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:19:14 by slynell           #+#    #+#             */
/*   Updated: 2020/07/15 12:57:14 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(register int32_t n)
{
	static const int32_t	sizes[10] = {9, 99, 999, 9999, 99999, 999999,
							9999999, 99999999, 999999999, INT32_MAX};
	register size_t			i;

	if (n < 0)
	{
		if (n == INT32_MIN)
			return (10);
		else
			n = -n;
	}
	i = 0;
	while (i++ < 11)
		if (n <= sizes[i - 1])
			return (i);
	return (10);
}
