/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 06:25:50 by dylan             #+#    #+#             */
/*   Updated: 2022/11/28 16:58:38 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *count);
void	processtype(char c, va_list ag_list, int *count);
void	ft_putstr(const char *src, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putnbru(unsigned int nb, int *count);
void	ft_hex(unsigned int nb, int *count, char c);
void	ft_putptr(uintptr_t nb, int *count, int io);

#endif