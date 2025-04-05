/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:02:53 by fhajanol          #+#    #+#             */
/*   Updated: 2025/04/04 13:45:38 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static char	**liberer(char **list, int i)
{
	while (--i >= 0)
		free(list[i]);
	free(list);
	return (NULL);
}


static size_t	ft_countword(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
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
		{
			if (*(s + 1) && *(s + 1) == c)
				result[i++] = ft_strdup("");
			s++;
		}
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