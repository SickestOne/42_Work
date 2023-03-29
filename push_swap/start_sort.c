/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:19:57 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/29 17:17:55 by rvan-den         ###   ########.fr       */
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
		ab = build_stack_sa(argc, str, 0);
		count_nodes(ab);
		print_list(ab);
		// swap_a(ab); // bug
	}
	else if (len > 5)
	{
		ab = build_stack_sa(argc, str, 0);
		count_nodes(ab);
		go_top(ab);
		print_list(ab);
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
		ab = build_stack(argc, str, 1);
		count_nodes(ab);
		go_top(ab);
		print_list(ab);
	}
	else if (len > 5)
	{
		ab = build_stack(argc, str, 1);
		count_nodes(ab);
		go_top(ab);
		print_list(ab);
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
