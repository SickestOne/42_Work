/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Diogo-ss <contact@diogosilva.dev>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:16:14 by Diogo-ss          #+#    #+#             */
/*   Updated: 2023/07/04 13:16:16 by Diogo-ss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     ft_atoi(const char *str)
{
        int     result;
        int     conv_sign;

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

long	ft_atol(const char *str)
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
