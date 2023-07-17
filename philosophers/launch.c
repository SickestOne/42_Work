/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:23:38 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/17 14:56:37by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  write_state(char *str, t_philo *ph)
{
  long int		time;

	time = -1;
	time = actual_time() - ph->pa->start_t;
  printf("%ld ", time);
  printf("philo %d %s", ph->ph_id, str);
}

void  *routine(void *arg)
{
  t_philo					*ph;

	ph = (t_philo *)arg;
  while (1)
  {
    pthread_mutex_lock(&ph->pa->wr_mtx);
    if (ph->ph_id % 2 == 0)
      write_state("is thinking\n", ph);
    else if (ph->ph_id % 2 != 0)
      write_state("is not thinking\n", ph);
    pthread_mutex_unlock(&ph->pa->wr_mtx);
    ft_usleep(200);
  }
  return (NULL);
}

int philo_start(t_p *phil)
{
  int i;

  i = -1;
  while (++i < phil->a.nb_phs)
  {
    phil->ph[i].pa = &phil->a;
    if (pthread_create(&phil->ph[i].th_id, NULL, routine, &phil->ph[i]))
      return (printf("Threads creation failed\n"), 0);
  }
  i = -1;
  while (++i < phil->a.nb_phs)
  {
    if (pthread_join(phil->ph[i].th_id, NULL))
      return (printf("Threads creation failed\n"), 0);
  }
  return (1);
}

