/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:09:06 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/30 10:42:19 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

t_bool	ft_is_valid_char(char c, char *s)
{
	int	i;

	if (s == NULL)
		return (false);
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (true);
		i++;
	}
	return (false);
}
