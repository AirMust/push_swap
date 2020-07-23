/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:20:25 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 10:20:25 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int data, size_t n)
{
	size_t	i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (i < n)
		str[i++] = data;
	return (str);
}
