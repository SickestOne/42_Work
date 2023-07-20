/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:27:44 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/20 17:21:30 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	operations(t_philo *ph)
{
	tf_df_eat(ph);
	ph_sleep(ph);
	ph_think(ph);
}

void	tf_df_eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->l_f);
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	if (!ph->r_f)
	{
		ft_usleep(ph->ph_args->t_die);
		return ;
	}
	pthread_mutex_lock(ph->r_f);
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("is eating\n", ph);
	pthread_mutex_lock(&ph->ph_args->time_eat);
	ph->ms_l_eat = actual_time();
	ph->nb_eat++;
	printf("philo %d have eat = %d and must eat %d times\n", ph->ph_id, ph->nb_eat, ph->ph_args->nb_m_eat);
	pthread_mutex_unlock(&ph->ph_args->time_eat);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	ft_usleep(ph->ph_args->t_eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(&ph->l_f);
}

void	ph_sleep(t_philo *ph)
{
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	ft_usleep(ph->ph_args->t_sleep);
}

void	ph_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("is thinking\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
}
