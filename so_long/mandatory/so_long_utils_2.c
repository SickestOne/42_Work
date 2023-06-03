/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:07:15 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/03 17:27:45 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int get_player_pos_x(char **map, int i, int j)
{
	int	x;

	x = 0;
    while (map[++i])
    {
        while (map[i][++j] && map[i][j + 1])
            if (map[i][j] == 'P')
				return (x = i);
        j = -1;
    }
    return (0);
}

int	get_player_pos_y(char **map, int i, int j)
{
	int	y;

	y = 0;
	while (map[++i])
	{
		while (map[i][++j] && map[i][j + 1])
			if (map[i][j] == 'P')
				return (y = j);
		j = -1;
	}
	return (0);
}

int	map_way(char **map, int px, int py)
{
	int collectible;

	collectible = get_collect(map);
	if (map[px][py] == 'P')
			map[px][py] = '0';
		if (map[px][py] == 'C')
		{
			collectible--;
			map[px][py] = '0';
		}
		if (map[px][py] == 'E' && collectible == 0)
			return (1);
		if (map[px][py] == '0')
		{
			map[px][py] = '1';
			if (map_way(map, (px - 1), py) || map_way(map, (px + 1), py)
				|| map_way(map, px, (py - 1)) || map_way(map, px, (py + 1)))
				return (1);
			return(0);
		}
		return (0);
}
