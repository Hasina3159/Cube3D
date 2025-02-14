/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:17:47 by fhajanol          #+#    #+#             */
/*   Updated: 2024/02/28 11:06:08 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *incr)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*incr += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', incr);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr (n / 10, incr);
		ft_putnbr (n % 10, incr);
	}
	else
		ft_putchar (n + '0', incr);
}

void	ft_unsigned(unsigned int n, int *incr)
{
	if (n >= 10)
		ft_unsigned(n / 10, incr);
	ft_putchar(n % 10 + '0', incr);
}
