/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/06 22:49:13 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// arguments du tableau
// 

# include "push_swap.h"

int	main(int argc,char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc < 2)
	{
		printf("Bad input detected, imbecile.\n");
		exit(1);
	}
	while (i < argc)
	{
		while (argv[j] != 0)
		{
			printf("%s\n", *ft_split(argv[i], ' '));
			if (ft_atoi(argv[i]) == 0)
				printf("Bad input detected, imbecile.\n");
			j++;
		}
		i++;
	}
	return (0);
}

// 1- Check de la liste emoyee : si bonne, push start. !bonne = err.
//		ft_atoi, ft_split -> tableau d'ints.
// 2- Feed to chained list.
// 3- fait deja les d
// eux etapes au dessus et on verras le reste apres.
