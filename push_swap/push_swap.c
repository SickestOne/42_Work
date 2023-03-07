/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/07 18:10:48 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int check_numbers(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			break;
		else 
			return (ft_atoi(argv[i]));
		i++;
	}
	return (0);
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
		if (check_numbers(&argv[i]) != 0)
			i++;
		else
		{
			printf("Bad input detected, imbecile.\n");
			exit(1);
		}
	}
	i = 1;
	while (i < argc)
	{
		printf("%d\n", check_numbers(&argv[i]));
		i++;
	}
}
/*to do : - iterer dans tout les args avant de pouvoir afficher le message d'erreur.
 * si err -> errno
 * ajout d'une fonction dans le main pour shrink.
 */
