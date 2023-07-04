/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:28:13 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/04 15:28:18 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//parsing

long			ft_atol(const char *str);
int				ft_atoi(const char *str);
int				letter_checker(char **av);
int				check_args(char **av);
int				int_checker(char **av);
int				is_num(char c);
void			print_errors(void);
void			ft_puterr(char *str);
long int		actual_time(void);
int				check_init(char **av);

//time

int				ft_usleep(long int time_in_ms);

///structs

typedef struct s_args
{
	int			num_forks;
	int			num_meals;
	int			num_of_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			is_dead;
	int			end;
	long int	start_time;
	long int	time_death;
}				t_args;

typedef struct s_philos
{
	int			id;
	t_args		philargs;
	pthread_t		t1;
	int				eat_cont;
	int				status;
	int				eating;
	long int		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_philos;
#endif
