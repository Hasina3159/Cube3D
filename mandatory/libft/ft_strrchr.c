/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:27:01 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:03 by ntodisoa         ###   ########.fr       */
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
