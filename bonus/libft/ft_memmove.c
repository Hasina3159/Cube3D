/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:11 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/25 10:35:16 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*sc1;
	const char	*sc2;

	sc1 = (char *)s1;
	sc2 = (const char *)s2;
	if (!s1 && !s2)
		return (NULL);
	if (sc2 < sc1 && sc1 < sc2 + n)
	{
		sc1 += n;
		sc2 += n;
		while (n > 0)
		{
			*--sc1 = *--sc2;
			n--;
		}
	}
	else
		while (n-- > 0)
			*sc1++ = *sc2++;
	return (s1);
}
