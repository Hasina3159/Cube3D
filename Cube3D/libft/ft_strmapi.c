/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:16:23 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/23 12:11:58 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*temp;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
