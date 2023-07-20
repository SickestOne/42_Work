/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:28:01 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/20 11:34:56 by rvan-den         ###   ########.fr       */
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

void  write_state(char *str, t_philo *ph)
{
	long int		time;
	time = -1;
	time = actual_time() - ph->ph_args->start_t;
	printf("%ld ", time);
	printf("philo %d %s", ph->ph_id, str);
}