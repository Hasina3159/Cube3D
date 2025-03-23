/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:35:57 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:22:58 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*c1;
	char	*c2;
	int		i;

	i = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (res);
	while (*c1)
	{
		res[i] = *c1;
		c1++;
		i++;
	}
	while (*c2)
	{
		res[i] = *c2;
		i++;
		c2++;
	}
	res[i] = '\0';
	return (res);
}
