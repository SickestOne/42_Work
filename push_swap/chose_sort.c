/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:35:58 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/26 19:35:45 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chose_sort_sa(char **str)
{
	char **temp;
	int len;

	temp = ft_split((const char *)str[1], ' ');
	len = sa_tab_len(temp);
	if (len >= 2 && len <= 5)
		printf("SA Use algo for len between 2 and 5\n");
	else if (len > 5)
		printf("SA Use algo for big ass lists\n");
	return (0);
}

int	chose_sort_ma(char **str)
{
	int len;

	len = ma_tab_len(str);
	if (len >= 2 && len <= 5)
		printf("MA Use algo for len between 2 and 5\n");
	else if (len > 5)
		printf("MA Use algo for big ass lists\n");
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
