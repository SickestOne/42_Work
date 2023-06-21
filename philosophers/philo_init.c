#include "philo.h"

int	args_init(t_args *ag_init, int ac, char **av)
{
	if (check_init(av))
	{
		ag_init->death = 0;
		ag_init->start_time = 0;
		ag_init->end = 0;
		ag_init->nb_ph = ft_atoi(av[1]);
		ag_init->time_die = ft_atol(av[2]);
		ag_init->time_eat = ft_atol(av[3]);
		ag_init->time_sleep = ft_atol(av[4]);
		if (ac == 6)
			ag_init->nb_mls = ft_atoi(av[5]);
		else
			ag_init->nb_mls = -1;
		pthread_mutex_init(&ag_init->dspy, NULL);
		pthread_mutex_init(&ag_init->lock, NULL);
		return (1);
	}
	return (0);
}

int	pthread_allocs(t_args *ag_init)
{
	ag_init->ids = malloc(sizeof(pthread_t) * (ag_init->nb_ph));
	if (!ag_init->ids)
		return (pth_alc_err(0), 0);
	ag_init->forks = malloc(sizeof(pthread_mutex_t) * (ag_init->nb_ph));
	if (!ag_init->forks)
		return (pth_alc_err(1), 0);
	ag_init->philos = malloc(sizeof(t_philos) * (ag_init->nb_ph));
	if (!ag_init->philos)
		return (pth_alc_err(2), 0);
	return (1);
}

//i start at -1;
void	create_forks(t_args *ag_init, int i)
{
	while (++i < ag_init->nb_ph)
		pthread_mutex_init(&ag_init->forks[i], NULL);
	i = 0;
	ag_init->philos[0].l_f = &ag_init->forks[0];
	ag_init->philos[0].r_f = &ag_init->forks[ag_init->nb_ph - 1];
	i = 1;
	while (i < ag_init->nb_ph)
	{
		ag_init->philos[i].l_f = &ag_init->forks[i];
		ag_init->philos[i].r_f = &ag_init->forks[i - 1];
		i++;
	}
}

void	create_philos(t_args *ag_init, int i)
{
	while (i < ag_init->nb_ph)
	{

		i++;
	}
}
