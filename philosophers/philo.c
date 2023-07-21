/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:26:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/21 15:10:32 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	check_arg(int ac, char **av)
{
	if (!letter_checker(av) || !int_checker(av) || !check_init(ac, av))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_p p;

	if (ac >= 5 && ac <= 6)
	{
		if (check_arg(ac, av))
		{
			game_init(ac, av, &p);
			p.ph = malloc(sizeof(t_philo) * p.a.nb_phs);
			if (!p.ph)
				return (printf("Philo malloc error\n"), 0);
			philo_init(&p);
			philo_start(&p);
			while (1)
				if (!monitoring(p.ph))
					exit (1);		
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
