/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:44:07 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/30 15:02:52 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
lst: L’élément à free
del: L’adresse de la fonction permettant de
supprimer le contenu de l’élément.

Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !(*del))
		return ;
	del(lst->content);
	free(lst);
}
