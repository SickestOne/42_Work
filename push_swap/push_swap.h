/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:14 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/30 18:46:38 by rvan-den         ###   ########.fr       */
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


int		count_params(char **s, char c, int i);
int		check_input(char *s, char c);
int		check_stack(int argc, char **str);
int		chose_sort_sa(int argc, char **str);
int		chose_sort_ma(int argc, char **str);
int		ma_checker(int argc, char **str);
int		double_checker(int argc, char **str, int i, int j);
long	ft_long_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		int_checker(char **str, int i);
int		number_checker(char **str, int i, int j);
int		sa_tab_len(char **temp);
int		ma_tab_len(char **temp);
int		retarded_input(char **str, int i);
int		sa_checker(char **argv);
int		sorted_stack_a_ma(int argc, char **str);
int		sorted_stack_a_sa(int argc, char **str);
int		sign_checker(char **str, int i, int j);
int		sort_checker_ma(int argc, char **str, int i, int j);
int		sort_checker_sa(int argc, char **str);
int		test_temp(char ** argv);
void	print_list_a(t_ctrl *ab);
void	print_list_b(t_ctrl *ab);
int		check_solo_sign(char **str, int i);
int		count_nodes_a(t_ctrl *ab);
int		count_nodes_b(t_ctrl *ab);
char	**ft_split(char const *s, char c);
t_node	*create_cell(int content);
t_ctrl	*build_stack_a_ma(int argc, char **argv, int i);
t_ctrl	*build_stack_a_sa(int argc, char **argv, int i);
t_ctrl	*build_stack_b_ma(int argc, char **argv, int i);
t_ctrl	*build_stack_b_sa(int argc, char **argv, int i);
t_ctrl	*go_top_a(t_ctrl *ab);
t_ctrl	*go_top_b(t_ctrl *ab);
t_ctrl	*swap_a(t_ctrl *ab, int i);
t_ctrl	*swap_b(t_ctrl *ab, int i);
t_ctrl	*s_s(t_ctrl *ab);
t_ctrl	*push_b(t_ctrl *ab, int i);
t_ctrl	*push_a(t_ctrl *ab, int i);

#endif
