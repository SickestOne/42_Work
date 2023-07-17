/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:28:13 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/17 13:43:31 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdint.h>

//parsing

long			ft_atol(const char *str);
int				ft_atoi(const char *str);
int				letter_checker(char **av);
int				check_args(int ac, char **av);
int				int_checker(char **av);
int				is_num(char c);
void			print_errors(void);
void			ft_puterr(char *str);
long int		actual_time(void);
int				check_init(int ac, char **av);
void			pth_alc_err(int i);

//utils

void	ft_putstr(char *s);

//time

int				ft_usleep(long int time_in_ms);

//structs
 typedef	struct        s_arg             //arguments after ./philo
{
	int                   nb_phs;            // number of philosophers
	int                   t_die;              // time to die in milliseconds
	int                   t_eat;              // time to eat in milliseconds
	int                   t_sleep;            // time to sleep in milliseconds
	int                   nb_m_eat;            // must eat m_eat times
	long int              start_t;          // start time in milliseconds
	pthread_mutex_t       wr_mtx;           // write mutex
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;      
	int                   ph_eat;      // when a philosopher ate m_eat times : nb_p_finish++
	int                   stop;             // 0 if none philosopher is dead, 1 if a philosopher is dead, 2 if all philosophers ate m_eat times
}                       t_arg;

typedef	struct          s_philo
{
	int                   ph_id;               // id of the philosopher
	pthread_t             th_id;        // thread id
	pthread_t             th_md_id;  // id of the thread monitoring death
	pthread_mutex_t       *r_f;             // right fork mutex
	pthread_mutex_t       l_f;              // left fork mutex
	t_arg                 *pa;              // pointer to structure with all arguments (pointer on a)
	long int              ms_l_eat;           // time of the last dinner in milliseconds
	unsigned int          nb_eat;           // number of dinners (each time the philosopher eats nb_eat++)
	int                   fnh_eat;           // 1 when a philosopher ate m_eat times, if not, 0
}                       t_philo;

typedef	struct          s_p
{
	t_philo               *ph;              // structure for each philosopher
	t_arg                 a;                // structure with arguments, same for all philosophers
}						t_p;

//mem_alloc && data_init

int game_init(int ac, char **av, t_p *rules);
int	philo_init(t_p *phil);
int philo_start(t_p *phil);
#endif
