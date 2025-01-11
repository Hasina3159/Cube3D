/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:27:01 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/25 08:39:59 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = -1;
	res = NULL;
	while (++i < ft_strlen(s) + 1)
		if ((unsigned char)s[i] == (unsigned char)c)
			res = ((char *)(s + i));
	return (res);
}
