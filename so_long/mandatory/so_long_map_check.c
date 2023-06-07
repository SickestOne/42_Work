/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:27:37 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/07 18:03:49 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_size(char **map, int i)
{
	int	map_size;
    
    map_size = ft_strlen(map[0]);
	while (map[++i])
		if (ft_strlen(map[i]) != map_size)
			err_msg(3);
    return (1);
}

int map_is_closed(char **map, int i, int j)
{
    int tab_size;

    tab_size = gmsy(map);
    while (map[++i])
    {
        while (map[i][++j] && map[i][j + 1] && map[i][j + 1] != '\n')
        {
            if (i == 0 && map[i][j] != '1')
                err_msg(4);
            else if (i > 0 && map[i][0] != '1')
                err_msg(4);
            else if (i == tab_size - 1 && map[i][j] != '1')
                err_msg(4);
        }
        if (map[i][j] != '1')
            err_msg(4);
        j = -1;
    }
    return (1);
}

int map_params(char **map, int i, int j, int par_p)
{
    int par_e;
    int par_c;

    par_e = 0;
    par_c = 0;
    while (map[++i])
    {
        while (map[i][++j] && map[i][j + 1] && map[i][j + 1] != '\n')
        {
           if (map[i][j] == 'P')
                par_p++;
            else if (map[i][j] == 'C')
                par_c++;
            else if (map[i][j] == 'E')
                par_e++;
        }
        j = -1;
    }
    if (par_c > 0 && par_e == 1 && par_p == 1)
        return (1);
    return (err_msg_2(1), 0);
}

int map_is_valid(char **map, int i, int j)
{
    while (map[++i])
    {
        while (map[i][j] && map[i][j + 1])
        {
            if (map[i][j] == '1' || map[i][j] == '0' ||
                map[i][j] == 'P' || map[i][j] == 'C' ||
                map[i][j] == 'E' || map[i][j] == 'F')
                j++;
            else
                err_msg_2(2);
        }
        j = 0;
    }
    return (1);
}
