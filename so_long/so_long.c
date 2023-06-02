/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:49:49 by pendejoo          #+#    #+#             */
/*   Updated: 2023/06/02 11:01:09 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc == 2)
        parse_init(argc, argv);
    fill_map_tab(argc, argv);
    check_map_size(argc, argv, fill_map_tab(argc, argv), 0);
    map_is_closed(fill_map_tab(argc, argv), -1, -1);
    map_params(fill_map_tab(argc, argv), 0, -1, 0);
    return (0);
}

int parse_init(int argc, char **argv)
{
    int     map_to_open;
    int i;

    i = 0;
    (void)argc;
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

char **fill_map_tab(int argc, char **argv)
{
   int          i;
   char     *temp;
   char **map_tab;
   int opened_map;

   temp = NULL;
   i = 0;
   opened_map = parse_init(argc, argv);
   map_tab = malloc(sizeof(map_tab) * get_malloc_size(argc, argv) + 1);
   if (!map_tab)
        return (NULL);
   while (1)
   {
        temp = get_next_line(opened_map);
        if (temp == NULL)
            break;
        map_tab[i] = temp;
        i++;
        temp = NULL;
   }
   map_tab[i] = NULL;
   return (map_tab);
}
