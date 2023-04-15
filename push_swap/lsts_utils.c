/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo </var/spool/mail/pendejoo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:24:35 by pendejoo          #+#    #+#             */
/*   Updated: 2023/04/15 22:44:06 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ctrl	*build_stack_a_ma(int argc, char **argv, int i)
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
	ab->a->rank = 0;
	go_top_a(ab);
	return (ab);
}

t_ctrl	*build_stack_a_sa(int argc, char **argv, int i)
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
	ab->a->rank = 0;
	ab = go_top_a(ab);
	return (ab);
}

t_ctrl	*give_ranks(t_ctrl *ab, int ranks)
{
	t_node *tmp;

	tmp = ab->a;
	while (check_ranks(ab) != 1)
	{
		while (ab->a != NULL)
		{
			if (tmp->data > ab->a->data && ab->a->rank == 0)
				tmp = ab->a;
			ab->a = ab->a->next;
		}
		ab->a = tmp;
		tmp->rank = ranks;
		ranks++;
		go_top_a(ab);
		if (check_ranks(ab))
			break ;
		while (ab->a->rank != 0)
			ab->a = ab->a->next;
		tmp = ab->a;
	}
	go_top_a(ab);
	return (ab);
}

/*void check_if_ranked(t_ctrl *ab)
{
	while
}*/
