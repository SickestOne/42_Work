/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:21:28 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/30 10:39:14 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: L’adresse du pointeur vers le premier élément
de la liste.
new: L’adresse du pointeur vers l’élément à
rajouter à la liste. */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_lst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_lst = ft_lstlast(*(lst));
	lst_lst->next = new;
}
