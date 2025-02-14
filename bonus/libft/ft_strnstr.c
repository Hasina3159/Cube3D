/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:25:23 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/26 09:33:54 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		little_len;
	size_t		j;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (!*big || len < little_len)
		return (NULL);
	while (i < len)
	{
		j = 0;
		while (i < len && j < little_len && big[i] == little[j])
		{
			i++;
			j++;
		}
		if (j == little_len)
			return ((char *)(big + (i - j)));
		i -= j;
		i++;
	}
	return (NULL);
}
