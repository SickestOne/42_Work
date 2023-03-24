/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:05:24 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/24 12:45:08 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TO DO : check number of args
// BUILD STACK if args >= 3
// GO TOP FUNCTION
// if 1 args, return term (already sorted)
// if no args, exit/return terr

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

t_ctrl	*build_stack(int argc, char **argv, int i)
{
	t_ctrl *ab;
	t_node *tmp;

	ab = malloc(sizeof(t_ctrl));
	if (!ab)
		return (NULL);
	ab->a = NULL;
	ab->b = NULL;
	ab->a = create_cell(ft_atoi(argv[i++]));
	tmp = ab->a;
	while (i < argc)
	{
		ab->a->next = create_cell(ft_atoi(argv[i]));
		ab->a = ab->a->next;
		ab->a->prev = tmp;
		tmp = ab->a;
		i++;
	}
	return (ab);
}
// fait la pute, oublie le premier nombre comme une gamine.
t_ctrl	*build_stack_sa(int argc, char **argv, int i)
{
	t_ctrl *ab;
	t_node *tmp;
	char	**temp;

	temp = ft_split((const char *)argv[i], ' ');
	argc = count_params(temp, ' ', 0);
	ab = malloc(sizeof(t_ctrl));
	if (!ab)
		return (NULL);
	ab->a = NULL;
	ab->b = NULL;
	ab->a = create_cell(ft_atoi(temp[i]));
	tmp = ab->a;
	while (i < argc)
	{
		ab->a->next = create_cell(ft_atoi(temp[i]));
		ab->a = ab->a->next;
		ab->a->prev = tmp;
		tmp = ab->a;
		i++;
	}
	return (ab);
}
