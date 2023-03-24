/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/24 21:50:42 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TO DO :
// - for argc == 2 et +1 num in argv -> split to list
// - faire une focntion pour gerer : "xx xx" xx xx.
// - dabord check si necessaire.

/*int	retarded_input(int argc, char **str)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (count_params(str, ' ', 1) > 1 && argc > 2)
			return (0);
		i++;
	}
	return (1);
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
	else if (!number_checker(str, 1, 0) || !double_checker(argc, str, 0, 1)
		|| !sign_checker(str, 1, 0) || !int_checker(str, -1)
		|| !sort_check(argc, str, 0, 1))
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

int	sort_check(int argc, char **str)
{
	int i;
	int j;
	int	temp;

	i = 1;
	j = i + 1;
	while (str[i])
	{
		temp = ft_atoi(str[i]);
		while (str[j])
		{
			if (ft_atoi(str[j]) > temp)
		}
	}
	return (1);
}
