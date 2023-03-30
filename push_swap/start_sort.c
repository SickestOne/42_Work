/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:19:57 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/30 19:04:44 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	chose_sort_sa(int argc, char **str)
{
	char **temp;
	t_ctrl *ab;
	int len;

	temp = ft_split((const char *)str[1], ' ');
	len = sa_tab_len(temp);
	ab = NULL;
	if (len >= 2 && len <= 5)
	{
		ab = build_stack_a_sa(argc, str, 0);
		print_list_a(ab);
		push_b(ab, 1);
		print_list_a(ab);
		push_b(ab, 1);
		print_list_a(ab);
	}
	else if (len > 5)
	{
		ab = build_stack_a_sa(argc, str, 0);
	}
	return (0);
}

int	chose_sort_ma(int argc, char **str)
{
	int len;
	t_ctrl *ab;

	len = ma_tab_len(str);
	ab = NULL;
	if (len >= 2 && len <= 5)
	{
		ab = build_stack_a_ma(argc, str, 1);
	}
	else if (len > 5)
	{
		ab = build_stack_a_ma(argc, str, 1);
	}
	return (0);
}

int	sa_tab_len(char **temp)
{
	int i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int	ma_tab_len(char **temp)
{
	int i;

	i = 1;
	while (temp[i])
		i++;
	return (i - 1);
}
