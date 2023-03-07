/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/07 19:19:26 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int check_numbers(int argc, char **argv)
{
	int i;

	i = 0;
	while (argv[i] && i < argc)
	{
		if (!ft_isdigit(argv[i]))
			break ;
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
		printf("Bad input detected.\n");
		exit (1);
	}
	while (i < argc)
	{
		args_checker(argc, &argv[i]);
		printf("%d\n", check_numbers(0, &argv[i]));
		i++;
	}
	return (0);
}
/*to do : - iterer dans tout les args avant de pouvoir afficher le message d'erreur.
 * si err -> errno
 * ajout d'une fonction dans le main pour shrink.
 */
