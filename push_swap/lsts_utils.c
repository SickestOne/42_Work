/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:24:35 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/27 16:19:37 by rvan-den         ###   ########.fr       */
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
	ab->a = create_cell(ft_long_atoi(argv[i++]));
	tmp = ab->a;
	while (i < argc)
	{
		ab->a->next = create_cell(ft_long_atoi(argv[i]));
		ab->a = ab->a->next;
		ab->a->prev = tmp;
		tmp = ab->a;
		i++;
	}
	return (ab);
}

t_ctrl	*build_stack_sa(int argc, char **argv, int i)
{
	t_ctrl *ab;
	t_node *tmp;
	char	**temp;

	temp = ft_split((const char *)argv[1], ' ');
	argc = count_params(temp, ' ', 0);
	ab = malloc(sizeof(t_ctrl));
	if (!ab)
		return (NULL);
	ab->a = NULL;
	ab->b = NULL;
	ab->a = create_cell(ft_long_atoi(temp[i++]));
	tmp = ab->a;
	while (i < argc)
	{
		ab->a->next = create_cell(ft_long_atoi(temp[i]));
		ab->a = ab->a->next;
		ab->a->prev = tmp;
		tmp = ab->a;
		i++;
	}
	return (ab);
}

t_ctrl	*go_top(t_ctrl *ab)
{
	while (ab->a->prev != NULL)
		ab->a = ab->a->prev;
	return (ab);
}

void	print_list(t_ctrl *ab)
{
	while (ab->a->next != NULL)
	{
		printf("%d\n", ab->a->data);
		ab->a = ab->a->next;
	}
	printf("%d\n", ab->a->data);
}
