/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/08 12:47:03 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int	main(int argc,char **argv)
{
	int i;

	i = 1;
	if (argc <= 1)
	{
		printf("No input detected.\n");
		exit (0);
	}
	if (data_checker(argv))
	{
		while (i < argc)
		{
			printf("%d\n", ft_atoi(argv[i]));
			i++;
		}
	}	
	return (0);
}
/*to do : - iterer dans tout les args avant de pouvoir afficher le message d'erreur.
 * si err -> errno
 * ajout d'une fonction dans le main pour shrink.
 */