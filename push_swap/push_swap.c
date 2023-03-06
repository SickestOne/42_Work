/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/03 21:32:09 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// arguments du tableau
// 

# include "push_swap.h"

t_list	*ft_lstnew(int *content)
{
	t_list	*new_el;

	new_el = malloc(sizeof(t_list));
	if (!new_el)
		return (NULL);
	new_el->num = content;
	new_el->next = NULL;
	return (new_el);
}

int	main(int argc,char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		printf("Bad input detected, imbecile.\n");
		exit(1);
	}
	while (i < argc)
	{
		printf("%d\n", ft_atoi(argv[i]));
		if (ft_atoi(argv[i]) == 0)
			printf("Bad input detected, imbecile.\n");
		i++;
	}
	return (0);
}

// 1- Check de la liste emoyee : si bonne, push start. !bonne = err.
//		ft_atoi, ft_split -> tableau d'ints.
// 2- Feed to chained list.
// 3- fait deja les d
// eux etapes au dessus et on verras le reste apres.
