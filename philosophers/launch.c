/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:23:38 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/13 14:54:02 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  *rout(void *arg)
{
  t_ctrl *philo;
  
  philo = (t_ctrl *)arg;
  while (1)
  {
    pthread_mutex_lock(&philo->r->write);
    printf("id philo %d\n", philo->r->philos[0].id);
    pthread_mutex_unlock(&philo->r->write);
    sleep(3);
  }
  return (NULL);
}

// creation des threads
int  thread_launch(t_ctrl *data)
{
  int i;

  i = -1;
  data->r->start_time = actual_time();
  while (++i < data->r->philo_num)
  {
    if (pthread_create(&data->r->thids[i] , NULL, &rout, (void *)data))
      return (printf("Thread creation failed.\n"), -1);
  }
  i = -1;
  while (++i < data->r->philo_num)
  {
    if (pthread_join(data->r->thids[i], NULL))
      return (printf("Thread join failed.\n"), -2);
  }
  return (0);
}

// Lancement des threads
int launch(t_ctrl *data, int ac, char **av)
{
  if (rules_init(data, ac, av) && mem_alloc(data) &&
      create_forks(data))
  {
    create_philos(data);
    thread_launch(data);
    return (1);
  }
  return (0);
}
