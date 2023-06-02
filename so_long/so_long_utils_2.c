/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:07:15 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/02 20:34:17 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clone_map(char **map)
{
	int	i;
	int	j;
	char **temp;

	i = -1;
	j = 0;
    temp = malloc(sizeof(temp) * get_tab_size(map) + 1);
	while (map[++i])
	{
		temp[j] = ft_strdup(map[i]);
		j++;
	}
	temp[i] = NULL;
	return (temp);
}