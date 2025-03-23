/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:17:49 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:04 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (!*s || start > ft_strlen(s))
		len = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (start < ft_strlen(s) && len > 0)
	{
		res[i] = s[start];
		start++;
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
