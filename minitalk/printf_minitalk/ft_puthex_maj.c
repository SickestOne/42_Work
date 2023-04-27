/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:50:20 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/27 10:35:54 by rvan-den         ###   ########.fr       */
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

static int	count_len_min(unsigned int nb)
{
	int	count;

	count = 0;
	if (!nb)
	{
		count += 1;
	}
	while (nb)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

static int	ft_hex_max_fpf(unsigned int nb)
{
	if (nb >= 16)
	{
		if (ft_hex_max_fpf(nb / 16) < 0)
			return (-2147483648);
		if (ft_hex_max_fpf(nb % 16) < 0)
			return (-2147483648);
	}
	else if (nb < 10)
	{
		if (ft_putchar(nb + 48) < 0)
			return (-2147483648);
	}
	else
	{
		if (ft_putchar(nb + 55) < 0)
			return (-2147483648);
	}
	return (1);
}

int	ft_puthex_maj(unsigned int nb)
{
	if (ft_hex_max_fpf(nb) < 0)
		return (-2147483648);
	return (count_len_min(nb));
}
