/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:23:38 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/12 15:25:12 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  *do_routine()
{
  printf("routine\n");
  return (NULL);
}

// creation des threads
int  thread_launch(t_rules *data)
{
  int i;

  i = -1;
  data->start_time = actual_time();
  while (++i < data->philo_num)
  {
    if (pthread_create(&data->thids[i] , NULL, &do_routine, NULL))
      return (printf("Thread creation failed.\n"), -1);
  }
  i = -1;
  while (++i < data->philo_num)
  {
    if (pthread_join(data->thids[i], NULL))
      return (printf("Thread join failed.\n"), -2);
  }
  return (0);
}

// Lancement des threads
int launch(t_rules *data, int ac, char **av)
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
