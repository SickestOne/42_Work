/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:27:22 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/14 14:39:42 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mem_alloc(t_ctrl *data)
{
	data->r->thids = malloc(sizeof(pthread_t) * (data->r->philo_num));
	if (!data->r->thids)
		return (pth_alc_err(0), -1);
	data->r->forks = malloc(sizeof(pthread_mutex_t) *(data->r->philo_num));
	if (!data->r->forks)
		return (pth_alc_err(1), -2);
	data->r->philos = malloc(sizeof(t_phils) * (data->r->philo_num));
	if (!data->r->philos)
		return (pth_alc_err(2), -3);
	return (1);
}

int	rules_init(t_ctrl *data, int ac, char **av)
{
	data->r = malloc(sizeof(t_rules));
	if (ac == 6)
		data->r->meals_nb = (int) ft_atoi(av[5]);
	else
		data->r->meals_nb = -1;
	data->r->philo_num = ft_atoi(av[1]);
	data->r->death_time = (u_int64_t) ft_atoi(av[2]);
	data->r->eat_time = (u_int64_t) ft_atoi(av[3]);
	data->r->sleep_time = (u_int64_t) ft_atoi(av[4]);
	data->r->dead = 0;
	data->r->finished = 0;
	pthread_mutex_init(&data->r->write, NULL);
	pthread_mutex_init(&data->r->lock, NULL);
	return (1);
}

void	create_philos(t_ctrl *data)
{
	int	i;

	i = 0;
	while (i < data->r->philo_num)
	{
		data->r->philos[i].id = i + 1;
		data->r->philos[i].time_to_die = data->r->death_time;
		data->r->philos[i].eat_cont = 0;
		data->r->philos[i].eating = 0;
		data->r->philos[i].status = 0;
		pthread_mutex_init(&data->r->philos[i].lock, NULL);
		i++;
	}
}

int	create_forks(t_ctrl *data)
{
	int	i;

	i = -1;
	while (++i < data->r->philo_num)
		pthread_mutex_init(&data->r->forks[i], NULL);
	i = 0;
	data->r->philos[0].l_fork = &data->r->forks[0];
	data->r->philos[0].r_fork = &data->r->forks[data->r->philo_num - 1];
	i = 1;
	while (i < data->r->philo_num)
	{
		data->r->philos[i].l_fork = &data->r->forks[i];
		data->r->philos[i].r_fork = &data->r->forks[i - 1];
		i++;
	}
	return (1);
}

