/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:17:00 by fhajanol          #+#    #+#             */
/*   Updated: 2024/03/03 07:40:02 by fhajanol         ###   ########.fr       */
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
