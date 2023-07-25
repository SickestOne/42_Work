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

int	eat_checker(t_philo *ph, t_arg *ag)
{
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
	{
		pthread_mutex_lock(&ph->ph_args->wr_mtx);
		printf("*** All philos ate %d times ***\n", ph->ph_args->nb_m_eat);
		pthread_mutex_unlock(&ph->ph_args->wr_mtx);
		return (1);
	}
	if ((int)ph->nb_eat == ag->nb_m_eat)
	{
		pthread_mutex_lock(&ph->ph_args->wr_mtx);
		ag->ph_all_eat++;
		ph->fnh_eat[0]++;
		pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	}
	return (0);
}

int	d_checker(t_philo *ph)
{
	if (eat_checker(ph, ph->ph_args))
		return (0);
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	if ((actual_time() - ph->ms_l_eat) >= ph->ph_args->t_die)
	{
		write_state("died\n", ph);
		pthread_mutex_unlock(&ph->ph_args->wr_mtx);
		return (0);
	}
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	return (1);
}

void	*routine(void *arg)
{
	t_philo					*ph;

	ph = (t_philo *)arg;
	if (ph->ph_args->nb_phs == 1)
	{
		write_state("has taken a fork\n", ph);
		ft_usleep(ph->ph_args->t_die);
		return (NULL);
	}
	if (ph->ph_id % 2 == 0 && ph->ph_id != 1)
		ft_usleep(2);
	while (operations(ph))
		;
	return (NULL);
}

int	philo_start(t_p *phil)
{
	int	i;

	i = -1;
	while (++i < phil->a.nb_phs)
	{
		phil->ph[i].ph_args = &phil->a;
		if (pthread_create(&phil->ph[i].th_id, NULL, routine, &phil->ph[i]))
			return (printf("Threads creation failed\n"), 0);
	}
	return (1);
}
