/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:57:26 by slynell           #+#    #+#             */
/*   Updated: 2020/07/15 12:57:08 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(register char *begin, register char *end)
{
	register char	tmp;

	while (end > begin)
	{
		tmp = *end;
		*end-- = *begin;
		*begin++ = tmp;
	}
}
