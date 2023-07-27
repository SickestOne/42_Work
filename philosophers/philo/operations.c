/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:27:44 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/26 12:52:21 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	operations(t_philo *ph)
{
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
		return (pthread_mutex_unlock(&ph->ph_args->wr_mtx) * 0);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	if (tf_df_eat(ph))
		return (0);
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
		return (0);
	if (!ph_sleep_think(ph))
		return (0);
	return (1);
}

int	tf_df_eat(t_philo *ph)
{
	if (!d_checker(ph))
		return (1);
	pthread_mutex_lock(&ph->l_f);
	pthread_mutex_lock(ph->r_f);
	if (!d_checker(ph))
	{
		pthread_mutex_unlock(&ph->l_f);
		pthread_mutex_unlock(ph->r_f);
		return (1);
	}
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("has taken a fork\n", ph);
	write_state("has taken a fork\n", ph);
	write_state("is eating\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	ph->ms_l_eat = actual_time();
	ph->nb_eat++;
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	ft_usleep(ph->ph_args->t_eat);
	pthread_mutex_unlock(&ph->l_f);
	pthread_mutex_unlock(ph->r_f);
	return (0);
}

int	ph_sleep_think(t_philo *ph)
{
	if (!d_checker(ph))
		return (0);
	if (*ph->ph_args->game_end == 1)
		return (0);
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	ft_usleep(ph->ph_args->t_sleep);
	if (!d_checker(ph))
		return (0);
	if (*ph->ph_args->game_end == 1)
		return (0);
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("is thinking\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	return (1);
}
