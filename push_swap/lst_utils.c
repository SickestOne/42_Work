/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:05:24 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/20 15:37:43 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
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
}

t_node	*ft_lstnew(int content)
{
	t_node	*new_el;

	new_el = malloc(sizeof(t_node));
	if (!new_el)
		return (NULL);
	new_el->data = content;
	new_el->next = NULL;
	return (new_el);
}

/*void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next;
	*lst = new;
}*/
