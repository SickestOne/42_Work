/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:23:38 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/14 16:25:07 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  *rout(void *arg)
{
  t_phils *philo;
  int i = 0;
  
  philo = (t_phils *)arg;
	while (philo->rules->dead == 0)
	{
    pthread_mutex_lock(&philo->rules->write);
    if (i == philo->rules->philo_num)
      i = 0;
    printf("id = %d\n", philo->rules->philos[i].id);
    i++;
    pthread_mutex_unlock(&philo->rules->write);
    sleep(2);
	}
	return ((void *)0);
}

// creation des threads
int  thread_launch(t_phils *data)
{
  int i;

  i = -1;
  data->rules->start_time = actual_time();
  while (++i < data->rules->philo_num)
  {
    if (pthread_create(&data->rules->thids[i] , NULL, &rout, data->rules->philos + i))
      return (printf("Thread creation failed.\n"), -1);
  }
  i = -1;
  while (++i < data->rules->philo_num)
  {
    if (pthread_join(data->rules->thids[i], NULL))
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
