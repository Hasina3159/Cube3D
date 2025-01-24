/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/24 10:48:49 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../includes/defines.h"
#include "../includes/functions.h"

size_t	ft_get_split_size(char **splitted)
{
	int	i;

	if (splitted == NULL)
		return (0);
	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

void	ft_free_split(char **splitted)
{
	int	i;

	if (splitted == NULL)
		return;
	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return;
}
