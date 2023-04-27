/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fpf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:52:13 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/27 10:36:12 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_putchar(char c)
{
	int	res;

	res = write (1, &c, 1);
	if (res == -1)
		return (-2147483648);
	return (1);
}

static int	count(long long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		count += 1;
		if (nb < 0)
			nb *= -1;
	}
	while (nb / 10)
	{
		nb /= 10;
		count++;
	}
	if (nb >= 1 && nb <= 9)
		count += 1;
	return (count);
}

int	ft_putnbr_fpf(long long nb)
{
	if (nb < 0)
	{
		if (ft_putchar('-') < 0)
			return (-2147483648);
		nb = -nb;
	}
	if (nb < 10)
	{
		if (ft_putchar(nb + '0') < 0)
			return (-2147483648);
	}
	else
	{
		if (ft_putnbr_fpf(nb / 10) < 0)
			return (-2147483648);
		if (ft_putchar(nb % 10 + '0') < 0)
			return (-2147483648);
	}
	return (0);
}

int	ft_putnbr_pf(long long nb)
{
	if (ft_putnbr_fpf(nb) < 0)
		return (-2147483648);
	return (count(nb));
}
