/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:14 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/24 17:25:55 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int	data;
	struct t_node *next;
	struct t_node *prev;
}				t_node;

typedef struct t_ctrl
{
	struct t_node *a;
	struct t_node *b;
}			t_ctrl;

char	*error_msg(void);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		count_params(char **s, char c, int i);
int		sa_checker(int argc, char **argv);
int		data_checker(int argc, char **str);
int		number_checker(char **str, int i, int j);
int		double_checker(int argc, char **str, int i, int j);
int		double_checker_fsa(int argc, char **str);
int		int_checker(char **str, int i);
int		sign_checker(char **str, int i, int j);
int		retarded_input(int argc, char **str);
t_node	*create_cell(int content);
t_ctrl	*build_stack(int argc, char **argv, int i);
t_ctrl	*build_stack_sa(int argc, char **argv, int i);
int test_temp(char ** argv);

#endif
