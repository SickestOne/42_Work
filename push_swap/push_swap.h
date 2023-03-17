/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:14 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/17 17:19:09 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node_a
{
	int	data;
	struct t_node_a *next;
}				t_node_a;

typedef struct t_node_b
{
	int	data;
	struct t_node_b *next;
}				t_node_b;

long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		data_checker(int argc, char **argv);
int		number_checker(char **str);
int		double_checker(int argc, char **str, int i, int j);
int		int_checker(char **str, int i);
t_node_a *node_init(int argc, char **argv);

#endif
