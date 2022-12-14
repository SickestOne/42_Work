/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:23:47 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/29 16:31:44 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* lst: Le début de la liste.
 * Retourne le derneir element de la liste.
 * Renvoie le dernier element de la liste.
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
