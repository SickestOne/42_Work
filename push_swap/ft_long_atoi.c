/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:33:23 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/10 18:50:17 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	result;
	long	conv_sign;

	result = 0;
	conv_sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
	if (*str == '-')
		conv_sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * conv_sign);
}
