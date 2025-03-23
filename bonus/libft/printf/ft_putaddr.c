/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:50:45 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:18:46 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(void *addr, int *incr)
{
	char					addr_c[16];
	unsigned long long int	addr_l;
	int						i;

	if (addr == NULL)
	{
		ft_putstr("(nil)", incr);
		return ;
	}
	addr_l = (unsigned long long int)addr;
	i = 16;
	while (addr_l > 0)
	{
		addr_c[i] = addr_l % 16;
		if (addr_c[i] < 10)
			addr_c[i] += '0';
		else
			addr_c[i] += 87;
		addr_l = addr_l / 16;
		i--;
	}
	i++;
	ft_putstr("0x", incr);
	while (i <= 16)
		ft_putchar(addr_c[i++], incr);
}
