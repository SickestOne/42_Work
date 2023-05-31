/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:44:15 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 16:31:19y rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// check si map a bonne extension
// mettre map dans **tab
// check les parties oblig su sujet
int main(int argc, char **argv)
{
    if (argc == 2)
        parse_init(argc, argv);
    return (0);
}

char **parse_init(int argc, char **argv)
{
    int     map_to_open;
    char    *map_to_parse;
    char    **map_tab;
    int i;

    i = 0;
    map_to_parse = NULL;
    map_to_open = open(argv[1], O_RDONLY, 0777);
    if (map_to_open == -1)
    {
        write(STDERR_FILENO, "Error\n", 6);
        perror("can't open map\n");
    }
    while (1)
    {
        map_to_parse = get_next_line(map_to_open);
        map_tab[i] = map_to_parse;
        i++;
        if (map_to_parse == NULL)
            break;
    }
    return (map_to_parse);
}


int check_map_size(char **map)
{
    int i;
    int map_len;
    
    i = 0;
    map_len = ft_strlen(map[0]);
    while (map[i])
        i++;
    while (map[++i])
    {
        if (map_len != ft_strlen(map[i]))
        {
            write(STDERR_FILENO, "Error\n", 6);
            perror("can't open map\n");
        }
    }
    return (1);
}