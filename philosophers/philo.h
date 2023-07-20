/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:28:13 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/20 10:45:16 by rvan-den         ###   ########.fr       */
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
 typedef	struct        s_arg
{
	pthread_mutex_t       wr_mtx;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;			//finish mutex
	int                   nb_phs;
	int                   t_die;
	int                   t_eat;
	int                   t_sleep;
	int                   nb_m_eat;            // must eat m_eat times
	long int              start_t;
	int                   ph_all_eat;      // when a philosopher ate m_eat times : nb_p_finish++
	int                   stop;             // 0 if none philosopher is dead, 1 if a philosopher is dead, 2 if all philosophers ate m_eat times
}                       t_arg;

typedef	struct          s_philo
{
	pthread_t             th_id;
	pthread_t             th_md_id;
	pthread_mutex_t       *r_f;
	pthread_mutex_t       l_f;
	int                   ph_id;
	long int              ms_l_eat;           // time of the last dinner in milliseconds
	unsigned int          nb_eat;           // number of dinners (each time the philosopher eats nb_eat++)
	int                   fnh_eat;           // 1 when a philosopher ate m_eat times, if not, 0
	t_arg                 *ph_args;
}                       t_philo;

typedef	struct          s_p
{
	t_philo               *ph;              // structure for each philosopher
	t_arg                 a;                // structure with arguments, same for all philosophers
}						t_p;

//mem_alloc && data_init

int game_init(int ac, char **av, t_p *rules);
int	philo_init(t_p *phil);

// operations
int		philo_start(t_p *phil);
void	write_state(char *str, t_philo *ph);
void	operations(t_philo *ph);
void	ph_sleep(t_philo *ph);
void	ph_think(t_philo *ph);
void	tf_df_eat(t_philo *ph);
int		monitoring(t_philo *ph);
#endif
