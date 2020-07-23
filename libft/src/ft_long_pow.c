/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:19:39 by slynell           #+#    #+#             */
/*   Updated: 2020/07/15 12:57:12 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_long_pow(const long double base, register int_fast16_t power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (ft_long_pow(1 / base, -power));
	if (power & 1)
		return (base * ft_long_pow(base, power - 1));
	return (ft_long_pow(base * base, power / 2));
}
