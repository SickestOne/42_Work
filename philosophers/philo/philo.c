/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:26:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/26 13:27:56 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *ph, t_arg *ags)
{
	free(ph->fnh_eat);
	free(ags->dead_stop);
	free(ags->game_end);
}

void	deconstructor(t_philo *ph, t_arg *ags)
{
	int	i;

	i = -1;
	while (++i < ags->nb_phs)
		pthread_join(ph[i].th_id, NULL);
	i = -1;
	while (++i < ags->nb_phs)
		pthread_mutex_destroy(&ph[i].l_f);
	pthread_mutex_destroy(&ags->wr_mtx);
	return ;
}

int	check_arg(int ac, char **av)
{
	if (!letter_checker(av) || !int_checker(av) || !check_init(ac, av))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_p	p;

	if (ac >= 5 && ac <= 6)
	{
		if (check_arg(ac, av))
		{
			game_init(ac, av, &p);
			p.ph = malloc(sizeof(t_philo) * (p.a.nb_phs));
			if (!p.ph)
				return (printf("Philo malloc error\n"), 0);
			philo_init(&p, -1);
			philo_start(&p);
			while (d_checker(p.ph))
				;
			deconstructor(p.ph, &p.a);
			free_all(p.ph, &p.a);
			free(p.ph);
			return (0);
		}
	}
	return (print_errors(), 0);
}
