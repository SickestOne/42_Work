/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/08 22:04:08 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// plus et moins
#include "push_swap.h"

int	letter_checker(char **str)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (((str[i][j] >= '0') && (str[i][j] <= '9')) || str[i][j] == '+' || str[i][j] == '-' ||
			str[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
/*
 * Compare la premiere string avec toutes les autres jusqua 0
 *  si une des autres == premiere string
 *			return (0);
 *	sinon
 *		passage a la deuxieme string, memes operations.
 *	return (1);	
 *
 *	ajout d'un holder temp pour comparer la string ?
 */

int	double_checker(int argc, char **str)
{
	int tab;
	int lettre;
	int i;
	char **temp;

	i = 1;
	tab = 1;
	lettre = 0;
	while(str[tab])
	{
		while (str[tab][lettre] && i <= argc)
		{
			double_checker_two(argc, str, temp);
		}
		tab = 0;
		lettre = 0;
		tab = argc;
		temp = NULL;
		i++;
	}
	return (1);
}

void double_checker_two(int argc, char **str, char **temp)
{}

int	data_checker(int argc, char **str)
{
	if (!(letter_checker(str)) || !double_checker(argc, str))
	{
		write(2, "Error\n", 7);
		exit (2);
	}
	else
		return (1);
}
