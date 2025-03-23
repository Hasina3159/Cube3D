/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:36:39 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:32 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_next(char type, va_list *pt, int *incr)
{
	if (type == 'c')
		ft_putchar(va_arg(*pt, int), incr);
	else if (type == 's')
		ft_putstr(va_arg(*pt, char *), incr);
	else if (type == 'd')
		ft_putnbr(va_arg(*pt, int), incr);
	else if (type == 'i')
		ft_putnbr_base((long long int)va_arg(*pt, int), \
		"0123456789", incr);
	else if (type == 'u')
		ft_unsigned(va_arg(*pt, unsigned int), incr);
	else if (type == 'x')
		ft_putnbr_base((long int)va_arg(*pt, unsigned int), \
		"0123456789abcdef", incr);
	else if (type == 'X')
		ft_putnbr_base((long int)va_arg(*pt, unsigned int), \
		"0123456789ABCDEF", incr);
	else if (type == 'p')
		ft_putaddr(va_arg(*pt, void *), incr);
	else if (type == '%')
		ft_putchar('%', incr);
}

int	ft_printf(const char *prompt, ...)
{
	va_list	ap;
	int		incr;

	incr = 0;
	va_start(ap, prompt);
	while (*prompt)
	{
		if (*prompt == '%')
		{
			prompt++;
			print_next(*prompt, &ap, &incr);
		}
		else
			ft_putchar(*prompt, &incr);
		prompt++;
	}
	va_end(ap);
	return (incr);
}
