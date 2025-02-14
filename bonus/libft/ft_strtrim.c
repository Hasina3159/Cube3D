/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:04:01 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/29 12:37:02 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	can_skip(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		r;

	r = 0;
	while (can_skip(*s1, set))
		s1++;
	i = (int)ft_strlen(s1);
	while (can_skip(s1[i - 1], set))
		i--;
	if (!*s1)
		i = 0;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	while (r < i)
	{
		res[r] = *s1;
		s1++;
		r++;
	}
	res[r] = '\0';
	return (res);
}
