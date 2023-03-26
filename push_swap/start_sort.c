/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:19:57 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/26 22:39:28 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	chose_sort_sa(char **str)
{
	char **temp;
	int len;

	temp = ft_split((const char *)str[1], ' ');
	len = sa_tab_len(temp);
	printf("nbr sa args : %d\n", len);
	if (len >= 2 && len <= 5)
	{
		//init_list_sa_ff(argc, temp);
		printf("ac == 2 Use algo for len between 2 and 5\n");
	}
	else if (len > 5)
	{
		//init_list_sa_fx(argc, temp);
		printf("ac == 2 Use algo for big ass lists\n");
	}
	return (0);
}

int	chose_sort_ma(char **str)
{
	int len;

	len = ma_tab_len(str);
	printf("nbr ma args : %d\n", len);
	if (len >= 2 && len <= 5)
	{
		//init_list_ma_ff(argc, str[1]); 
		printf("ac > 2 Use algo for len between 2 and 5\n");
	}
	else if (len > 5)
	{
		//init_list_ma_fx(argc, str[1]); 
		printf("ac > 2 Use algo for big ass lists\n");
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
