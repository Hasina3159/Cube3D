/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:20:40 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/25 08:33:59 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s) + 1)
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
	return (NULL);
}
