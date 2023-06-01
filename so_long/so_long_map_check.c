/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:27:37 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/01 13:47:18 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     check_map_size(int argc, char **argv, char **map, int i)
{
    int map_size;
    int l_tab_size;
    int tab_size;

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
