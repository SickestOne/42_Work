/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:49:49 by pendejoo          #+#    #+#             */
/*   Updated: 2023/06/03 17:38:40 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
    int tab[2];

    if (argc == 2)
        parse_init(argv);
    fill_map_tab(argv);
    check_map_size(fill_map_tab(argv), -1);
    map_is_closed(fill_map_tab(argv), -1, -1);
    map_params(fill_map_tab(argv), 0, -1, 0);
    map_is_valid(fill_map_tab(argv), -1, 0);
    tab[0] = get_player_pos_x(fill_map_tab(argv), -1, -1);
    tab[1] = get_player_pos_y(fill_map_tab(argv), -1, -1);
    if (!map_way(clone_map(fill_map_tab(argv)), tab[0], tab[1]))
        err_msg_2(3);
    return (0);
}

int parse_init(char **argv)
{
    int     map_to_open;
    int i;

    i = 0;
    map_to_open = open(argv[1], O_RDONLY, 0777);
    if (map_to_open == -1)
        err_msg(2);
    if (check_extension(argv[1]) == 0)
        err_msg(1);
    return (map_to_open);
}

int check_extension(char *str)
{
    char    **split_av;
    int     nb_ltab;
    
    nb_ltab = 0;
    split_av = ft_split(str, '.');
    while (split_av[nb_ltab])
        nb_ltab++;
    if (ft_strncmp(split_av[nb_ltab - 1], "ber", 3) == 0)
        return (free_tabs(split_av), 1);
    return (free_tabs(split_av), 0);
}

char **fill_map_tab(char **argv)
{
   int          i;
   char     *temp;
   char **map_tab;
   int opened_map;

   temp = NULL;
   i = 0;
   opened_map = parse_init(argv);
   map_tab = malloc(sizeof(map_tab) * get_malloc_size(argv) + 1);
   if (!map_tab)
        return (NULL);
   while (1)
   {
        temp = get_next_line(opened_map);
        if (temp == NULL)
            break;
        map_tab[i] = ft_strtrim(temp, "\n");
        i++;
        temp = NULL;
   }
   map_tab[i] = NULL;
   return (map_tab);
}
