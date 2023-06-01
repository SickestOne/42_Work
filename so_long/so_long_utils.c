/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:41:03 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/01 13:04:51 by rvan-den         ###   ########.fr       */
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
	int size;
	int	i;

	i = 0;
	size = 0;
	while (tab[i][0])
	{
		size = i;
		i++;
	}
	return (size);
}