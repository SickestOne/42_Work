/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:27:37 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/02 10:56:14 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(int argc, char **argv, char **map, int i)
{
	int	map_size;
	int	l_tab_size;
	int	tab_size;

	tab_size = get_malloc_size(argc, argv);
	map_size = ft_strlen(map[i]);
	while (map[i])
	{
		if (i != tab_size)
			l_tab_size = ft_strlen(map[i]);
		if (i == tab_size - 1 || i == tab_size)
			map_size -= 1;
		if (l_tab_size != map_size)
			err_msg(3);
		if (i == tab_size - 1)
			map_size += 1;
        i++;
		if (i == tab_size)
			break;
    }
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
    if (par_c > 0 && par_e > 0 && par_p > 0)
        return (1);
    return (err_msg_2(1), 0);
}
