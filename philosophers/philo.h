#ifndef	PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <semaphore.h>

long	ft_atol(const char *str);
int		letter_checker(char **av);
int		check_args(char **av);
int		int_checker(char **av);
int     ft_atoi(const char *str);
int		is_num(char c);
void	print_errors(void);

typedef struct t_philo
{
	int	num_forks;
	int	num_of_philo;
	int	time_die;
	int time_eat;
	int	time_sleep;
	struct	t_philo	*next;
	struct	t_philo	*prev;
}                                       t_philo;
#endif