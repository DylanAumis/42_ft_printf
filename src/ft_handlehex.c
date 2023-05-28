/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlehex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:58:49 by dylan             #+#    #+#             */
/*   Updated: 2023/05/28 17:31:49 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_hex(unsigned int nb, int *count, char c)
{
	if (nb >= 16)
	{
		ft_hex(nb / 16, count, c);
		ft_hex(nb % 16, count, c);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'), count);
		else
		{
			if (c == 'x')
				ft_putchar((nb - 10 + 'a'), count);
			if (c == 'X')
				ft_putchar((nb - 10 + 'A'), count);
		}
	}
}

void	ft_putptr(uintptr_t nb, int *count, int io)
{
	if (nb != 0)
	{
		if (io == 0)
		{
			io = 1;
			ft_putstr(("0x"), count);
		}
	}
	if (nb == 0 && io == 0)
	{
		ft_putstr(("(nil)"), count);
		return ;
	}
	if (nb >= 16)
	{
		ft_putptr(nb / 16, count, io);
		ft_putptr(nb % 16, count, io);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'), count);
		else
			ft_putchar((nb - 10 + 'a'), count);
	}
}
