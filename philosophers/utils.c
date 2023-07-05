/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:28:01 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/05 12:35:27 by rvan-den         ###   ########.fr       */
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

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		write (1, &s[i++], 1);
}