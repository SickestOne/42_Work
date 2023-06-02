/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:27:37 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/02 16:56:26 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(int argc, char **argv, char **map, int i)
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

    tab_size = get_tab_size(map);
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
    int tab_size;
    int par_e;
    int par_c;

    par_e = 0;
    par_c = 0;
    tab_size = get_tab_size(map);
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
                map[i][j] == 'E')
                j++;
            else
                err_msg_2(2);
        }
        j = 0;
    }
    return (1);
}

int can_do_map(char **map, int *tab, int mx, int my)
{
    int collect;
    int py;
    int px;
    char **tmp_map;

    collect = get_collect(map);
    mx = ft_strlen(map[0]);
    my = get_tab_size(map);
    py = tab[0];
    px = tab[1];
    tmp_map = NULL;
    return (1);
}
