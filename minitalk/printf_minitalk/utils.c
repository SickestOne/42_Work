/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:43:45 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/02 14:44:17 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	conv_sign;

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
