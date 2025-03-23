/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:48:33 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:17:27 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rev(char *res)
{
	size_t	i;
	char	temp;

	i = 0;
	while (i < ft_strlen(res) / 2)
	{
		temp = res[i];
		res[i] = res[ft_strlen(res) - i - 1];
		res[ft_strlen(res) - i - 1] = temp;
		i++;
	}
	return (res);
}

static int	max_size(long long n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*zero(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char		*r;
	int			pos;
	long long	cur;

	if (n == 0)
		return (zero());
	r = (char *)malloc(sizeof(char) * max_size(n));
	if (!r)
		return (NULL);
	pos = 0;
	cur = (long long)n;
	if (cur < 0)
		cur *= -1;
	while (cur > 0)
	{
		r[pos++] = (cur % 10) + '0';
		cur /= 10;
	}
	if (n < 0)
		r[pos++] = '-';
	r[pos] = '\0';
	return (ft_rev(r));
}
