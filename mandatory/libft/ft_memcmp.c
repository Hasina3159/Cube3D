/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:06:01 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:22:39 by ntodisoa         ###   ########.fr       */
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
