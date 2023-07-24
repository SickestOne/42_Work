/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:27:44 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/21 17:26:06rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	case_1(t_philo *ph)
{
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	pthread_mutex_unlock(&ph->l_f);
}

int	operations(t_philo *ph)
{
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
		return (0);
	if (!d_checker(ph))
		return (0);
	if (tf_df_eat(ph))
		return (0);
	if (!d_checker(ph))
		return (0);
	ph_sleep(ph);
	ph_think(ph);
	return (1);
}

int	tf_df_eat(t_philo *ph)
{
	
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	pthread_mutex_lock(&ph->l_f);
	write_state("has taken a fork\n", ph);
	if (!ph->r_f)
	{
		ft_usleep(ph->ph_args->t_die);
		return (case_1(ph), 1);
	}
	pthread_mutex_lock(ph->r_f);
	write_state("has taken a fork\n", ph);
	write_state("is eating\n", ph);
	ph->ms_l_eat = actual_time();
	ph->nb_eat++;
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	if (eat_checker(ph, ph->ph_args))
	{
		pthread_mutex_unlock(ph->r_f);
		pthread_mutex_unlock(&ph->l_f);
		return (1);
	}
	ft_usleep(ph->ph_args->t_eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(&ph->l_f);
	return (0);
}

void	ph_sleep(t_philo *ph)
{
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
		return ;
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
	ft_usleep(ph->ph_args->t_sleep);
}

void	ph_think(t_philo *ph)
{
	if (ph->fnh_eat[0] == ph->ph_args->nb_phs)
		return ;
	pthread_mutex_lock(&ph->ph_args->wr_mtx);
	write_state("is thinking\n", ph);
	pthread_mutex_unlock(&ph->ph_args->wr_mtx);
}
