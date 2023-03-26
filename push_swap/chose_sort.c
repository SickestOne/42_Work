/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:35:58 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/26 18:34:26 by pendejoo         ###   ########.fr       */
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
		printf("Use algo for len between 2 and 5\n");
	else if ((sa_tab_len(temp) > 5))
		printf("Use algo for big ass lists\n");
	return (0);
}

/*int	chose_sort_ma(int argc, char **str)
{

}*/

int	sa_tab_len(char **temp)
{
	int i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}
