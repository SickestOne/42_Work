/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:24:58 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/24 20:01:05 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int game_init(int ac, char **av, t_p *rules)
{
	if (ac == 6)
		rules->a.nb_m_eat = ft_atoi(av[5]);
	else
		rules->a.nb_m_eat = -1;
	rules->a.nb_phs = ft_atoi(av[1]);
	rules->a.t_die = ft_atoi(av[2]);
	rules->a.t_eat = ft_atoi(av[3]);
	rules->a.t_sleep = ft_atoi(av[4]);
	rules->a.stop = 0;
	rules->a.start_t = actual_time();
	rules->a.ph_all_eat = 0;
	pthread_mutex_init(&rules->a.wr_mtx, NULL);
	return (1);
}

int	philo_init(t_p *phil)
{
	int	i;
	int *count;

	i = -1;
	count = malloc(sizeof(int));
	count[0] = 0;
	while (++i < phil->a.nb_phs)
	{
		phil->ph[i].ph_id = i + 1;
		phil->ph[i].ms_l_eat = phil->a.start_t;
		phil->ph[i].nb_eat = 0;
		phil->ph[i].fnh_eat = count;
		phil->ph[i].r_f = NULL;
		pthread_mutex_init(&phil->ph[i].l_f, NULL);
		if (phil->a.nb_phs == 1)
			return (1);
		if (i == phil->a.nb_phs - 1)
			phil->ph[i].r_f = &phil->ph[0].l_f;
		else
			phil->ph[i].r_f = &phil->ph[i + 1].l_f;
	}
	return (1);
}
