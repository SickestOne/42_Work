/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:38:57 by rvan-den          #+#    #+#             */
/*   Updated: 2022/12/13 15:08:35 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
del: L’adresse de la fonction permettant de
supprimer le contenu d’un élément.

Itère sur la liste ’lst’ et applique la fonction
’f ’au contenu de chaque élément. Crée une nouvelle
liste résultant des applications successives de
’f’. La fonction ’del’ est là pour détruire le
contenu d’un élément si nécessaire. */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_lst;
	t_list	*link;
	t_list	*new;

	link = 0;
	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		tmp_lst = (*f)(lst->content);
		new = ft_lstnew(tmp_lst);
		if (!new)
		{
			free(tmp_lst);
			ft_lstclear(&link, del);
			return (NULL);
		}
		ft_lstadd_back(&link, new);
		lst = lst->next;
	}
	return (link);
}
