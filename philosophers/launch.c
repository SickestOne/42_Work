/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:23:38 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/20 10:57:02rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eat_checker(t_philo *ph)
{
  int i;

  i = 0;
  pthread_mutex_lock(&ph->ph_args->time_eat);
  while (42)
  {
    if (i == ph->ph_args->nb_phs)
      i = 0;
    if (ph->ph_args->ph_all_eat == ph->ph_args->nb_m_eat)
      break ;
    if (ph[i].fnh_eat != 1 && (int)ph[i].nb_eat >= ph->ph_args->nb_m_eat)
    {
      ph[i].fnh_eat += 1;
      ph->ph_args->ph_all_eat += 1;
      printf("all_eat %d\n", ph->ph_args->ph_all_eat);
    }
    i++;
    pthread_mutex_unlock(&ph->ph_args->time_eat);
  }
  pthread_mutex_unlock(&ph->ph_args->time_eat);
  return (1);
}

int death_checker(t_philo *ph)
{
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
  if (!death_checker(ph) || eat_checker(ph))
    return (0);
  return (1);
}

void  *routine(void *arg)
{
  t_philo					*ph;

	ph = (t_philo *)arg;
  if (ph->ph_id % 2 == 0)
    ft_usleep(ph->ph_args->t_die / 10);
  while (42)
    operations(ph);
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
  }
  i = -1;
  while (++i < phil->a.nb_phs)
  {
    if (pthread_detach(phil->ph[i].th_id))
      return (printf("Threads creation failed\n"), 0);
  }
  return (1);
}

