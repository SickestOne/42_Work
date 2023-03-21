/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:05:24 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/21 20:57:05 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	printf("adresse ab->a avant compute :%p\n\n", ab->a);
	tmp = ab->a;
	while (i < argc)
	{
		ab->a->next = create_cell(ft_atoi(argv[i]));
		ab->a = ab->a->next;
		ab->a->prev = tmp;
		tmp = ab->a;
		i++;
	}
	printf("adresse ab->a apres compute :%p\n", ab->a);
	return (ab);
}

// TO DO : check number of args
// BUILD STACK if more than 2
//

/*void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next;
	*lst = new;
}*/

/*void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*lst_lst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_lst = ft_lstlast(*(lst));
	lst_lst->next = new;
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}*/
