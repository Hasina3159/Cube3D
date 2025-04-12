/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:02:53 by fhajanol          #+#    #+#             */
/*   Updated: 2025/04/12 09:33:35 by ntodisoa         ###   ########.fr       */
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

void	_nothing(const char **s, char c, char **result, size_t *i)
{
	while (**s == c)
	{
		if (*((*s)++ + 1) && **(s) == c)
			result[(*i)++] = ft_strdup("");
	}
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
		_nothing(&s, c, result, &i);
		if (!*s)
			break ;
		len = 0;
		while (*s && *s != c && ++len)
			s++;
		result[i++] = ft_substr(s - len, 0, len);
		if (!result[i - 1])
			return (liberer(result, (int)i));
	}
	result[i] = 0;
	return (result);
}
