/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlei.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:59:34 by dylan             #+#    #+#             */
/*   Updated: 2023/05/28 17:31:53 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ismin(int nb, int *count)
{
	ft_putstr("-2", count);
	nb = 147483648;
	return (nb);
}

int	isneg(int nb, int *count)
{
	ft_putchar('-', count);
	return (-nb);
}

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
		nb = ismin(nb, count);
	if (nb < 0)
		nb = isneg(nb, count);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
	else
		ft_putchar((nb + '0'), count);
}
