/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den < rvan-den@student.42mulhouse.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:19:42 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/27 11:21:26 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		if (count_args(argv[i], ' ') == 0)
			return (0);
	return (1);
}

int	count_args(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i + 1])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i] != c && i == '\0'))
			count++;
		i++;
	}
	return (count);
}
