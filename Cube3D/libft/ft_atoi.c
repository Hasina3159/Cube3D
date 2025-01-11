/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:34:44 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/23 10:26:21 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_white(char c)
{
	char	*white;

	white = "\r\f\v\n\t ";
	while (*white)
	{
		if (*white == c)
			return (1);
		white++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	int		result;
	char	*temp;

	i = 0;
	temp = (char *)str;
	while (is_white(*temp))
		temp++;
	signe = 1;
	result = 0;
	if (temp[i] == '-' || temp[i] == '+')
	{
		if (temp[i] == '-')
			signe = -1;
		i++;
	}
	while (temp[i] != '\0' && (temp[i] <= '9' && temp[i] >= '0'))
	{
		result *= 10;
		result += temp[i] - '0';
		i++;
	}
	return (result * signe);
}
