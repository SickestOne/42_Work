/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:07:15 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/06 16:25:53 by rvan-den         ###   ########.fr       */
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
    temp = malloc(sizeof(temp) * gmsy(map) + 1);
	while (map[++i])
	{
		temp[j] = ft_strdup(map[i]);
		j++;
	}
	temp[i] = NULL;
	return (temp);
}

int gpx(char **map, int i, int j)
{
    while (map[++i])
    {
        while (map[i][++j] && map[i][j + 1])
            if (map[i][j] == 'P')
				return (j);
        j = -1;
    }
    return (0);
}

int	gpy(char **map, int i, int j)
{
	while (map[++i])
	{
		while (map[i][++j] && map[i][j + 1])
			if (map[i][j] == 'P')
				return (i);
		j = -1;
	}
	return (0);
}

int	map_way(char **map, int px, int py)
{
	static int collectible = 0;
	int	map_x;
	int map_y;

	if (!map)
		return (-1);
	map_x = ft_strlen(map[0]);
	map_y = gmsy(map);
	if (py < 0 || py >= map_y || px < 0 || px >= map_x
		|| map[py][px] == '1')
		return (0);
	if (map[py][px] == 'C' || map[py][px] == 'E')
		collectible++;
	map[py][px] = '1';
	map_way(map, px - 1, py);
	map_way(map, px + 1, py);
	map_way(map, px, py - 1);
	map_way(map, px, py + 1);
	return (collectible);
}

int	map_way_ok(char **map, int px, int py)
{
	int	collect;

	collect = get_collect(map);
	return (map_way(map, px, py) == collect + 1);
}
