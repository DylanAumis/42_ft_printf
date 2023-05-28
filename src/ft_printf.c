/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:21:34 by dylan             #+#    #+#             */
/*   Updated: 2023/05/28 17:32:03 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	processtype(char c, va_list a_list, int *count)
{
	int	io;

	io = 0;
	if (c == 'c')
		ft_putchar((char)va_arg(a_list, int), count);
	else if (c == 's')
		ft_putstr((const char *)va_arg(a_list, char *), count);
	else if (c == 'p')
		ft_putptr((uintptr_t)va_arg(a_list, void *), count, io);
	else if (c == 'i' || c == 'd')
		ft_putnbr((int)va_arg(a_list, int), count);
	else if (c == 'u')
		ft_putnbru((unsigned int)va_arg(a_list, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_hex((unsigned int)va_arg(a_list, unsigned int), count, c);
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ag_list;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(ag_list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			processtype(str[i], ag_list, &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(ag_list);
	return (count);
}
