/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:27:22 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/15 12:17:13 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mem_alloc(t_phils *data)
{
	data->p_r->philos = malloc(sizeof(t_phils) * (data->p_r->philo_num));
	if (!data->p_r->philos)
		return (pth_alc_err(2), -3);
	data->p_r->thids = malloc(sizeof(pthread_t) * (data->p_r->philo_num));
	if (!data->p_r->thids)
		return (pth_alc_err(0), -1);
	data->p_r->forks = malloc(sizeof(pthread_mutex_t) *(data->p_r->philo_num));
	if (!data->p_r->forks)
		return (pth_alc_err(1), -2);
	return (1);
}

int	rules_init(t_phils *data, int ac, char **av)
{
	data->p_r = malloc(sizeof(t_rules));
	if (!data->p_r)
		return (printf("Rules alloc Error\n"), -4);
	if (ac == 6)
		data->p_r->meals_nb = ft_atoi(av[5]);
	else
		data->p_r->meals_nb = -1;
	data->p_r->philo_num = ft_atoi(av[1]);
	data->p_r->death_time = ft_atoi(av[2]);
	data->p_r->eat_time = ft_atoi(av[3]);
	data->p_r->sleep_time = ft_atoi(av[4]);
	data->p_r->dead = 0;
	data->p_r->finished = 0;
	pthread_mutex_init(&data->p_r->write, NULL);
	pthread_mutex_init(&data->p_r->lock, NULL);
	mem_alloc(data);
	return (1);
}

void	create_philos(t_phils *data)
{
	int	i;

	i = 0;
	while (i < data->p_r->philo_num)
	{
		data->p_r->philos[i].id = i + 1;
		data->p_r->philos[i].time_to_die = data->p_r->death_time;
		data->p_r->philos[i].eat_cont = 0;
		data->p_r->philos[i].eating = 0;
		data->p_r->philos[i].status = 0;
		pthread_mutex_init(&data->p_r->philos[i].lock, NULL);
		i++;
	}
}

int	create_forks(t_phils *data)
{
	int	i;

	i = -1;
	while (++i < data->p_r->philo_num)
		pthread_mutex_init(&data->p_r->forks[i], NULL);
	i = 0;
	data->p_r->philos[0].l_fork = &data->p_r->forks[0];
	data->p_r->philos[0].r_fork = &data->p_r->forks[data->p_r->philo_num - 1];
	i = 1;
	while (i < data->p_r->philo_num)
	{
		data->p_r->philos[i].l_fork = &data->p_r->forks[i];
		data->p_r->philos[i].r_fork = &data->p_r->forks[i - 1];
		i++;
	}
	return (1);
}

int launch(t_phils *data, int ac, char **av)
{
  if (rules_init(data, ac, av) &&
      create_forks(data))
  {
    thread_launch(data);
    return (1);
  }
  return (0);
}

