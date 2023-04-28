/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/28 13:16:13 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	retarded_input(char **str, int i)
{
	while (str[i + 1])
	{
		if ((check_input(str[i], ' ') && !check_input(str[i + 1], ' '))
			|| (!check_input(str[i], ' ') && check_input(str[i + 1], ' ')))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i] != c && i == '\0'))
			count++;
		i++;
	}
	if (count == 1)
		return (0);
	return (count);
}

int	sa_checker(char **str)
{
	char	**temp;
	int		argc_d;

	if (!count_params(str, ' ', 1))
		exit (0);
	temp = ft_split((const char *)str[1], ' ');
	if (count_params(temp, ' ', 0))
	{
		argc_d = count_params(temp, ' ', 0);
		if (number_checker(temp, 0, 0)
			&& double_checker(argc_d, temp, 0, 1)
			&& sign_checker(temp, 1, 0) && int_checker(temp, -1)
			&& check_solo_sign(temp, 0))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ma_checker(int argc, char **str)
{
	if (!number_checker(str, 1, 0) || !double_checker(argc, str, 1, 2)
		|| !sign_checker(str, 1, 0) || !int_checker(str, -1)
		|| !retarded_input(str, 1) || !check_solo_sign(str, 1))
		return (0);
	else
		return (1);
}

int	check_stack(int argc, char **str)
{
	check_sa_single(argc, str);
	if (argc > 2 && sorted_stack_a_ma(argc, str) == 1)
		return (1);
	else if (argc == 2 && sorted_stack_a_sa(argc, str) == 1)
		return (2);
	else if ((argc > 2 && sorted_stack_a_ma(argc, str) == -1)
		|| (argc == 2 && sorted_stack_a_sa(argc, str) == -1))
	{
		write (2, "Error\n", 7);
		exit(2);
	}
	exit (0);
}
