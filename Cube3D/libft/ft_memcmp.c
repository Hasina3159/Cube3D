/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:06:01 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/25 09:25:59 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t length)
{
	const char	*t1;
	const char	*t2;

	t1 = (const char *)s1;
	t2 = (const char *)s2;
	if (length == 0)
		return (0);
	while (length > 1)
	{
		if ((unsigned char)*t1 != (unsigned char)*t2)
			return ((unsigned char)*t1 - (unsigned char)*t2);
		t1++;
		t2++;
		length--;
	}
	return ((unsigned char)*t1 - (unsigned char)*t2);
}
