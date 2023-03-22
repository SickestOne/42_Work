/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:14 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/22 22:48:34 by pendejoo         ###   ########.fr       */
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

long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	**free_all(char **tab, size_t indice);
static int	count_words(char const *s, char c);
static char	*insert_s(char const *s, char c, int next_w);
int		data_checker(int argc, char **argv);
int		number_checker(char **str, int i, int j);
int		double_checker(int argc, char **str, int i, int j);
int		int_checker(char **str, int i);
int		sign_checker(char **str, int i, int j);
t_node	*create_cell(int content);
t_ctrl	*build_stack(int argc, char **argv, int i);
int		quotes_checker(int argc, char **str, int i);

#endif
