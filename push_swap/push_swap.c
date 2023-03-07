/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/07 14:34:17 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// arguments du tableau
// 

# include "push_swap.h"
char *check_numbers(char **argv)
{
	int i;

	i = 0;
	ft_split(argv[i], ' ');
	ft_atoi(argv[i]);
	return (argv[i]);
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
		printf("%s\n", check_numbers(&argv[i]));
		i++;
	}
	return (0);
}

/* 1- Check de la liste emoyee : si bonne, push start. !bonne = err.
		ft_atoi, ft_split -> tableau d'ints.
 2- Feed to chained list.
 3- fait deja les d
eux etapes au dessus et on verras le reste apres.*/ 
