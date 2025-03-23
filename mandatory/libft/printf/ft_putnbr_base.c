/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:07:28 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:37 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_min_max(long long int l_nbr, const char *base, int *incr)
{
	if (l_nbr == LONG_MIN && ft_strlen((char *)base) == 16)
	{
		ft_putstr("0", incr);
		return (1);
	}
	if (l_nbr >= LONG_MAX && ft_strlen((char *)base) == 16)
	{
		if (ft_strncmp(base, "0123456789abcdef", 16) == 0)
			ft_putstr("ffffffff", incr);
		else
			ft_putstr("FFFFFFFF", incr);
		return (1);
	}
	return (0);
}

int	is_zero(long long int l_nbr, int *incr)
{
	if (l_nbr == 0)
	{
		ft_putchar('0', incr);
		return (1);
	}
	return (0);
}

void	ft_putnbr_base(long int l_nbr, const char *base, int *incr)
{
	char			arr_nbr[16];
	int				base_div;
	int				i;

	base_div = ft_strlen((char *)base);
	if (is_min_max(l_nbr, base, incr) || is_zero(l_nbr, incr))
		return ;
	if (l_nbr < 0)
	{
		l_nbr = -l_nbr;
		ft_putchar('-', incr);
	}
	i = 0;
	while (l_nbr > 0)
	{
		arr_nbr[i] = base[l_nbr % base_div];
		l_nbr /= base_div;
		i++;
	}
	if (i > 8 && base_div == 16)
		i = 8;
	while (i-- > 0)
		ft_putchar(arr_nbr[i], incr);
}
