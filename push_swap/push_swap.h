/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:14 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/10 17:50:42 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		num;
	struct s_list *next; //modele assiette
}t_list;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		check_numbers(int argc, char **argv);
int		ft_isdigit(char *str);
int		ft_isascii(int c);
int		data_checker(int argc, char **argv);
int		letter_checker(char **str);
int		double_strcmp(int argc, char **str, int j, int i);
int		int_checker(char **str, int i);

#endif
