/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:14 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/18 10:51:33 by rvan-den         ###   ########.fr       */
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
	int	rank;
	struct t_node *next;
	struct t_node *prev;
}				t_node;

typedef struct t_ctrl
{
	struct t_node *a;
	struct t_node *b;
}			 t_ctrl;


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
void	print_list_a(t_ctrl *ab);
void	print_list_b(t_ctrl *ab);
int		check_solo_sign(char **str, int i);
int		count_nodes_a(t_ctrl *ab);
int		count_nodes_b(t_ctrl *ab);
char	**ft_split(char const *s, char c);
void	find_move_for_4(t_ctrl	*ab);
void	find_move_for_5(t_ctrl *ab);
t_node	*create_cell(int content, int ranks);
t_ctrl	*build_stack_a_ma(int argc, char **argv, int i);
t_ctrl	*build_stack_a_sa(int argc, char **argv, int i);
t_ctrl	*build_ranks(t_ctrl	*ab);
t_ctrl	*go_top_a(t_ctrl *ab);
t_ctrl	*go_top_b(t_ctrl *ab);
t_ctrl	*swap_a(t_ctrl *ab, int i);
t_ctrl	*swap_b(t_ctrl *ab, int i);
t_ctrl	*s_s(t_ctrl *ab);
t_ctrl	*push_b(t_ctrl *ab, int i);
t_ctrl  *push_b_link_last(t_ctrl *ab, int tmp_data, int tmp_rank);
t_ctrl	*push_b_clean_a(t_ctrl *ab, int node_count_a);
t_ctrl	*push_a(t_ctrl *ab, int i);
t_ctrl  *push_a_link_last(t_ctrl *ab, int tmp_data, int tmp_rank);
t_ctrl	*push_a_clean_b(t_ctrl *ab, int node_count_b);
t_ctrl	*rotate_a(t_ctrl *ab, int i);
t_ctrl	*rotate_a_linklast(t_ctrl *ab, int tmp_data, int tmp_rank);
t_ctrl	*rotate_b(t_ctrl *ab, int i);
t_ctrl	*rotate_b_linklast(t_ctrl *ab, int tmp_data, int tmp_rank);
t_ctrl	*r_r(t_ctrl *ab);
t_ctrl	*rra(t_ctrl *ab, int i);
t_ctrl	*go_down_a(t_ctrl *ab);
t_ctrl	*clean_down_a(t_ctrl *ab);
t_ctrl	*rrb(t_ctrl *ab, int i);
t_ctrl	*go_down_b(t_ctrl *ab);
t_ctrl	*clean_down_b(t_ctrl *ab);
t_ctrl	*rrr(t_ctrl *ab);
t_ctrl	*sort_for_3(t_ctrl	*ab);
t_ctrl	*sort_for_3_p2(t_ctrl *ab);
t_ctrl	*sort_for_5(t_ctrl *ab);
t_ctrl	*sort_small(t_ctrl *ab, int len);
t_ctrl	*give_ranks(t_ctrl *ab, int ranks);
void	check_if_ranked(t_ctrl *ab);
int		check_ranks(t_ctrl *ab);
t_ctrl	*move_first_20(t_ctrl *ab);
t_ctrl	*move_number(t_ctrl *ab);
int		check_ranks_b(t_ctrl *ab);
t_ctrl	*give_ranks_b(t_ctrl *ab, int ranks);
int		find_min(t_ctrl *ab);
int		find_max(t_ctrl *ab);
int		find_min_pos_b(t_ctrl *ab);
int		find_max_b(t_ctrl *ab);
t_ctrl	*move_big(t_ctrl *ab);
void	put_maxs_in_b(t_ctrl *ab, int total_len, int cut_coef, int *loop_var);
void	fill_a(t_ctrl *ab, int inter_max, int inter_min);
void	combine_sorted_stacks(t_ctrl *ab, int cut_coef, int total_len);
int		a_is_sorted(t_ctrl *ab);
int		find_max_pos_b(t_ctrl *ab);
void	fill_b(t_ctrl *ab, int inter_max, int inter_min);
void	fill_b_opti(t_ctrl *ab, int inter_max, int inter_min, int cut_coef);

#endif
