/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:28:13 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/05 16:20:10 by rvan-den         ###   ########.fr       */
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
void			pth_alc_err(int i);

//mem_alloc && data_init

int	mem_alloc(t_rules *data);
int	init_rules(t_rules *data,int ac, char **av);

//utils

void	ft_putstr(char *s);

//time

int				ft_usleep(long int time_in_ms);

///structs
typedef struct s_phils
{
	struct s_rules	*data;
	pthread_t       t1;
	int             id;
	int             eat_cont;
	int             status;
	int             eating;
	uint64_t        time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_phils;

typedef struct s_rules
{
	pthread_t       *tid;
	int             philo_num;
	int             meals_nb;
	int             dead;
	int             finished;
	t_phils         *philos;
	u_int64_t       death_time;
	u_int64_t       eat_time;
	u_int64_t       sleep_time;
	u_int64_t       start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
} t_rules;
#endif
