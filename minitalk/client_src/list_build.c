/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:30:27 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/02 15:29:01 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_node	*create_cell(unsigned char c)
{
	t_node	*cell;

	cell = malloc(sizeof(t_node));
	if (!cell)
		return (NULL);
	cell->letter = c;
	cell->ascii = c;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}

int	count_params(char **str, char c, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	if (!**str)
		return (0);
	while (str[i])
	{
		while (str[i][j])
		{
			if ((str[i][j] == c && str[i][j + 1] != c) ||
				(str[i][j] != c && str[i][j + 1] == '\0'))
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}
// modifie cette fonction pour ta liste.
t_ctrl	*build_stack(int argc, char **argv, int i)
{
	t_ctrl	*list;
	t_node	*tmp;
	char	**temp;

	temp = ft_split((const char *)argv[1], ' ');
	argc = count_params(temp, ' ', 0);
	list = malloc(sizeof(t_ctrl));
	if (!list)
		return (NULL);
	list->a = NULL;
	ab->b = NULL;
	ab->a = create_cell(ft_atoi(temp[i++]));
	tmp = ab->a;
	while (i < argc)
	{
		ab->a->next = create_cell(ft_long_atoi(temp[i]));
		ab->a = ab->a->next;
		ab->a->prev = tmp;
		tmp = ab->a;
		i++;
	}
	ab->a->rank = 0;
	ab = go_top_a(ab);
	return (ab);
}
