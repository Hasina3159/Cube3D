/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:29:39 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/25 10:04:48 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*su1;
	const char	*su2;

	su1 = (char *)s1;
	su2 = (const char *)s2;
	if (!s1 && !s2)
		return (NULL);
	while (0 < n)
	{
		*su1 = *su2;
		su1++;
		su2++;
		n--;
	}
	return (s1);
}
