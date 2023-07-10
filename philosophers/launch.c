/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:23:38 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/10 16:59:55 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  *routine()
{
  t_rules *data;

  printf("philo is here\n");
  return (NULL);
}

int  thread_launch(t_rules *data)
{
  int i;

  i = -1;
  while (++i < data->philo_num)
  {
    if (pthread_create(&data->philos[i].t1 , NULL, &routine, NULL))
      return (printf("Error\n"), -1);
    if (pthread_join(data->philos[i].t1, NULL))
      return (printf("Error2\n"), -2);
  }
  return (1);
}

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
