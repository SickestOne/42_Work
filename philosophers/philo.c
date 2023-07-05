/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:26:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/05 14:05:02 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac >= 5 && ac <= 6)
	{
		if (check_args(av))
		{
			ft_putstr("Confiture de cum\tBien sale\n");
		}
		else
		{
			printf("Error\nCheck your input.\n");
			return (0);
		}
	}
	else
		print_errors();
	return (0);
}

int	check_args(char **av)
{
	if (!letter_checker(av) || !int_checker(av) || !check_init(av))
		return (0);
	return (1);
}
