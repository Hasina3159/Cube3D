/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:02:53 by fhajanol          #+#    #+#             */
/*   Updated: 2024/03/01 10:47:48 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**liberer(char **list, int i)
{
	while (--i >= 0)
		free(list[i]);
	free(list);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	result = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!result)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (*s && *s != c && ++len)
			++s;
		result[i++] = ft_substr(s - len, 0, len);
		if (!result[i - 1])
			return (liberer(result, (int)i));
	}
	result[i] = 0;
	return (result);
}
