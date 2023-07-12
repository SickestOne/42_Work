/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:27:22 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/12 13:47:59 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mem_alloc(t_rules *data)
{
	data->thids = malloc(sizeof(pthread_t) * (data->philo_num));
	if (!data->thids)
		return (pth_alc_err(0), -1);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
	if (!data->forks)
		return (pth_alc_err(1), -2);
	data->philos = malloc(sizeof(t_phils) * (data->philo_num));
	if (!data->philos)
		return (pth_alc_err(2), -3);
	return (1);
}

int	rules_init(t_rules *data, int ac, char **av)
{
	if (ac == 6)
		data->meals_nb = (int) ft_atoi(av[5]);
	else
		data->meals_nb = -1;
	data->philo_num = (int) ft_atoi(av[1]);
	data->death_time = (u_int64_t) ft_atoi(av[2]);
	data->eat_time = (u_int64_t) ft_atoi(av[3]);
	data->sleep_time = (u_int64_t) ft_atoi(av[4]);
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (1);
}

void	create_philos(t_rules *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_cont = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int	create_forks(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->philo_num)
		pthread_mutex_init(&rules->forks[i], NULL);
	i = 0;
	rules->philos[0].l_fork = &rules->forks[0];
	rules->philos[0].r_fork = &rules->forks[rules->philo_num - 1];
	i = 1;
	while (i < rules->philo_num)
	{
		rules->philos[i].l_fork = &rules->forks[i];
		rules->philos[i].r_fork = &rules->forks[i - 1];
		i++;
	}
	return (1);
}
