/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/24 16:36:56 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TO DO :
// - for argc == 2 et +1 num in argv -> split to list
// - faire une focntion pour gerer : "xx xx" xx xx.
// - dabord check si necessaire.

/*	int	retarded_input(int argc, char **str)
{

}*/
int	sa_checker(int argc, char **str)
{
	char	**temp;

	temp = ft_split((const char *)str[1], ' ');
	if (count_params(temp, ' ', 0))
	{
		if (number_checker(temp, 1, 0) && double_checker(argc, temp, 0, 1)
			&& sign_checker(temp, 1, 0) && int_checker(temp, -1))
		{
			printf("sa rdy\n");
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	data_checker(int argc, char **str)
{
	if (argc == 2)
	{
		if (sa_checker(argc, str))
			return (2);
		else
		{
			write(2, "Error\n", 7);
			exit (2);
		}
	}
	/*else if (sa_checker(argc, str) && argc > 2) // A CORRIGER, SEGFAULT SUR ATOI
		exit (0);*/ 
	else if (!number_checker(str, 1, 0) || !double_checker(argc, str, 0, 1)
		|| !sign_checker(str, 1, 0) || !int_checker(str, -1))
	{
		write(2, "Error\n", 7);
		exit (2);
	}
	else
	{
		printf("ma rdy\n");
		return (1);
	}
}
