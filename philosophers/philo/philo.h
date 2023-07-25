/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:28:13 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/25 10:11:39 by rvan-den         ###   ########.fr       */
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
int				check_init(int ac, char **av);
void			print_errors(void);
void			ft_puterr(char *str);
void			pth_alc_err(int i);

//time

int				ft_usleep(long int time_in_ms);
long int		actual_time(void);

//structs
 typedef	struct        s_arg
{
	pthread_mutex_t       wr_mtx;
	int                   nb_phs;
	int                   t_die;
	int                   t_eat;
	int                   t_sleep;
	int                   nb_m_eat;
	long int              start_t;
	int                   ph_all_eat;
}                       t_arg;

typedef	struct          s_philo
{
	pthread_t             th_id;
	pthread_mutex_t       *r_f;
	pthread_mutex_t       l_f;
	int                   ph_id;
	long int              ms_l_eat;
	unsigned int          nb_eat;
	int                   *fnh_eat;
	t_arg                 *ph_args;
}                       t_philo;

typedef	struct          s_p
{
	t_philo               *ph;
	t_arg                 a;
}						t_p;

//mem_alloc & data_init

int	game_init(int ac, char **av, t_p *rules);
int	philo_init(t_p *phil);

// operations

int		philo_start(t_p *phil);
int		operations(t_philo *ph);
void	ph_sleep_think(t_philo *ph);
int		tf_df_eat(t_philo *ph);
int		eat_checker(t_philo *ph, t_arg *ag);
void	deconstructor(t_philo *ph, t_arg *ags);
int 	d_checker(t_philo *ph);

//utils

void	write_state(char *str, t_philo *ph);

#endif
