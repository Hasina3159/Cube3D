/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:45:15 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/23 10:23:40 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		ch;
	size_t				i;

	i = 0;
	p = s;
	ch = c;
	while (i < n)
	{
		if (p[i] == ch)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
