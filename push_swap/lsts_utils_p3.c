/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils_p3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:45:48 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/11 21:19:53 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_list_b(t_ctrl *ab)
{
	if (ab->b == NULL)
	{
		printf("b : is empty\n");
		return ;
	}
	while (ab->b->next != NULL)
	{
		printf("b : %d\n", ab->b->data);
		ab->b = ab->b->next;
	}
	printf("b : %d\n", ab->b->data);
	go_top_b(ab);
}

int	check_ranks(t_ctrl *ab)
{
	while (ab->a->next != NULL)
	{
		if (ab->a->rank == 0)
			return (0);
		ab->a = ab->a->next;
	}
	return (1);
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

t_node	*create_cell(int content)
{
	t_node *cell;

	cell = malloc(sizeof(t_node));
	if (!cell)
		return (NULL);
	cell->data = content;
	cell->next = NULL;
	cell->prev = NULL;
	return (cell);
}
