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

int	d_checker(t_philo *ph)
{
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	if (*ph->ph_args->dead_stop == 1)
		return (pthread_mutex_unlock(&ph->ph_args->wr_mtx) * 0);
	if ((actual_time() - ph->ms_l_eat) >= ph->ph_args->t_die)
	{
		*ph->ph_args->dead_stop = 1;
		write_state("died\n", ph);
		return (pthread_mutex_unlock(&ph->ph_args->wr_mtx) * 0);
	}
	if ((int)ph->nb_eat == ph->ph_args->nb_m_eat)
	{
		ph->ph_args->ph_all_eat++;
		ph->nb_eat++;
		ph->fnh_eat[0]++;
	}
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
	{
		ph->ph_args->game_end[0] = 1;
		return (pthread_mutex_unlock(&ph->ph_args->wr_mtx) * 0);
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
		if (!d_checker(ph))
			break ;
	return (NULL);
}

int	philo_start(t_p *phil)
{
	int	i;

	i = -1;
	while (++i < phil->a.nb_phs)
	{
		phil->ph[i].ph_args = &phil->a;
		if (pthread_create(&phil->ph[i].th_id, NULL, &routine, &phil->ph[i]))
			return (printf("Threads creation failed\n"), 0);
	}
	return (1);
}
