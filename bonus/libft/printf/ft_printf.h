/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:59:07 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/08 12:18:44 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int			ft_printf(const char *prompt, ...);
void		ft_putchar(char c, int *incr);
void		ft_putnbr(int n, int *incr);
void		ft_putstr(char *s, int *incr);
size_t		ft_strlen(const char *str);
void		ft_putnbr_base(long int nbr, const char *base, int *incr);
void		ft_putaddr(void *addr, int *incr);
void		ft_unsigned(unsigned int n, int *incr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
