#ifndef	PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <semaphore.h>

//parsing

long	ft_atol(const char *str);
int     ft_atoi(const char *str);
int		letter_checker(char **av);
int		check_args(char **av);
int		int_checker(char **av);
int		is_num(char c);
void	print_errors(void);
void	ft_puterr(char *str);
long int		actual_time(void);

//time

int	ft_usleep(long int time_in_ms);

///structs

typedef struct s_args
{
	int	num_forks;
	int	num_of_philo;
	int	time_die;
	int time_eat;
	int	time_sleep;
	long int 	start_time;
}                                       t_args;

typedef	struct s_philos
{
	int	id;
	t_args philargs;
}										t_philos;

typedef	struct s_ctrl_p
{
	t_philos	*philos;
	t_args		args;
}										t_ctrl_p;


#endif