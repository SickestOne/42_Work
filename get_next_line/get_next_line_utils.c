/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:12:58 by rvan-den          #+#    #+#             */
/*   Updated: 2023/01/06 15:28:49 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
int	ft_putnbr(long long nb)
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
		if (ft_putnbr(nb / 10) < 0)
			return (-2147483648);
		if (ft_putchar(nb % 10 + '0') < 0)
			return (-2147483648);
	}
	return (0);
}
