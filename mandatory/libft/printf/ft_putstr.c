/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:17:00 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:39 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *temp, int *incr)
{
	if (temp != NULL)
	{
		while (*temp != '\0')
		{
			ft_putchar(*temp, incr);
			temp++;
		}
	}
	else
		ft_putstr("(null)", incr);
}
