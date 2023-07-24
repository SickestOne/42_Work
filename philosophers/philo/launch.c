/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:11:44 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/24 14:41:5 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eat_checker(t_philo *ph, t_arg *ag)
{
	if (ph->fnh_eat[0] == ag->nb_phs)
		return (1);
	if ((int)ph->nb_eat == ag->nb_m_eat)
	{
		ag->ph_all_eat++;
		pthread_mutex_lock(&ph->ph_args->time_eat);
		ph->fnh_eat[0]++;
		pthread_mutex_unlock(&ph->ph_args->time_eat);
	}
	return (0);
}

int d_checker(t_philo *ph)
{
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
		return (0);
	pthread_mutex_lock(&ph->ph_args->time_eat);
	if ((actual_time() - ph->ms_l_eat) >= ph->ph_args->t_die)
	{
		pthread_mutex_lock(&ph->ph_args->wr_mtx);
		write_state("died\n", ph);
		pthread_mutex_unlock(&ph->ph_args->time_eat);
		pthread_mutex_unlock(&ph->ph_args->wr_mtx);
		return (0);
	}
	pthread_mutex_unlock(&ph->ph_args->time_eat);
	return (1);
}

int  monitoring(t_philo *ph)
{
	if (!d_checker(ph))
		return (0);
	return (1);
}

void  *routine(void *arg)
{
	t_philo					*ph;

	ph = (t_philo *)arg;
	if (ph->ph_id % 2 == 0)
		ft_usleep(ph->ph_args->t_eat);
	while (42)
		if (!operations(ph))
			break ;
	return (NULL);
}

int philo_start(t_p *phil)
{
	int i;

	i = -1;
	while (++i < phil->a.nb_phs)
	{
		phil->ph[i].ph_args = &phil->a;
		if (pthread_create(&phil->ph[i].th_id, NULL, routine, &phil->ph[i]))
			return (printf("Threads creation failed\n"), 0);
		ft_usleep(50);
	}
	i = -1;
	return (1);
}
