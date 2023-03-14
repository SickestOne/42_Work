/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:38:14 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/14 15:17:50 by rvan-den         ###   ########.fr       */
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

typedef struct s_list
{
	int		num;
	struct s_list *next; //modele assiette
}t_list;

long	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		data_checker(int argc, char **argv);
int		number_checker(char **str);
int		double_checker(int argc, char **str, int i, int j);
int		int_checker(char **str, int i);

#endif
