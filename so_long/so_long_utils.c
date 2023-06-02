/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:41:03 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/01 15:28:24by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tabs(char **tab)
{
	int	j;

	j = -1;
	while (tab[++j])
		free(tab[j]);
	free(tab);
}

int get_malloc_size(int argc, char **argv)
{
    int size;
    int map_open;
    char *temp;
    
    temp = NULL;
    size = 0;
    map_open = parse_init(argc, argv);
    while (1)
    {
        temp = get_next_line(map_open);
        if (temp == NULL)
            break;
        size++;
    }
    close(map_open);
    return (size);
}

int	get_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
        i++;
	return (i);
}

int get_collect(char **map)
{
    int i;
    int j;
    int collect;

    i = -1;
    j = 0;
    collect = 0;
    while (map[++i])
    {
        while (map[i][j] && map[i][j + 1])
        {
            if (map[i][j] == 'C')
                collect++;
            j++;
        }
        j = 0;
    }
    return (collect);
}

int *get_player_pos(char **map, int i, int j, int *tab)
{
    tab[0] = 0;
    tab[1] = 0;
    while (map[++i])
    {
        while (map[i][++j] && map[i][j + 1])
        {
            if (map[i][j] == 'P')
            {
                tab[0] = i;
                tab[1] = j;
            }
        }
        j = -1;
    }
    return (tab);
}