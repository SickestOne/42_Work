/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:50:56 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/02 15:12:40 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

typedef	struct t_node
{
	unsigned char letter;
	int				ascii;
	struct	t_node	*next;
	struct	t_node	*prev;
}				t_node;

typedef	struct t_ctrl
{
	struct t_node	*atob;
}				t_ctrl;

int			ft_printf(const char *fmt, ...);
static int	ft_putchar(char c);
static int	count(long long nb);
int			ft_putnbr_fpf(long long nb);
int			ft_putnbr_pf(long long nb);
static int	count_len_min(unsigned int nb);
static int	ft_hex_min_fpf(unsigned int nb);
int			ft_puthex_min(unsigned int nb);
static int	ft_hex_max_fpf(unsigned int nb);
int			ft_puthex_maj(unsigned int nb);
static int	count_len_ptradr(unsigned long long ptr);
static int	ft_ptr_adr(unsigned long long ptr);
int			ft_ptradress(unsigned long long ptr);
static void	ft_format(va_list ap, const char *fmt, int i, int *len);
int			ft_do_s(char *str);
int			ft_do_pct(int c);
int			ft_do_c(int c);
void		test_server(void);
void		go_top(t_ctrl *i);
t_node		*create_cell(unsigned char c);
int			count_params(char **str, char c, int i);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);

#endif


