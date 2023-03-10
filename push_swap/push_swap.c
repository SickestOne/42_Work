/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:15:18 by pendejoo          #+#    #+#             */
/*   Updated: 2023/03/10 16:58:40 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int	main(int argc,char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
	{
		exit (0);
	}
	if (data_checker(argc, argv))
			printf("OK\n");
	return (0);
}
/*to do : - iterer dans tout les args avant de pouvoir afficher le message d'erreur.
 * si err -> errno
 * ajout d'une fonction dans le main pour shrink.
 */
