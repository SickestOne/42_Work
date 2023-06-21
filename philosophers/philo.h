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
void	pth_alc_err(int i);


//time

void	ft_usleep(long int time_in_ms);
long int		actual_time(void);

///structs

typedef	struct s_philos
{
	struct	s_args *data;
	pthread_t	t_1;
	int	id;
	int	eat_counter;
	int is_eating;
	int	status;
	long int	tt_die;
	pthread_mutex_t lock;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*l_f;
}		           t_philos;

typedef struct s_args
{
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t	dspy;
	pthread_t	*t_ids;
	t_philos	*philos;
	int			nb_ph;
	int			nb_mls;
	int			death;
	int			end;
	long int	time_die;
	long int	time_eat;
	long int	time_sleep;
	long int 	start_time;
}                   t_args;


//init

int	args_init(t_args *ag_init, int ac, char **av);
int	check_init(char **av);
void	create_forks(t_args *ag_init, int i);

#endif