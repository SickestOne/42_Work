/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/06 16:27:54 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// arguments du tableau
// 

# include "push_swap.h"

/*t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	new_el = malloc(sizeof(t_list));
	if (!new_el)
		return (NULL);
	new_el->num = content;
	new_el->next = NULL;
	return (new_el);
}*/

int	main(int argc,char **argv)
{
	int i;

	i = 1;
	if (argc != 2)
	{
		printf("bouge de la fdp\n");
		exit(1);
	}
	while (i < argc)
	{
		printf("%d\n", ft_atoi(argv[i]));
		i++;
	}
	return (0);
}
