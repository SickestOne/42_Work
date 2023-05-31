/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo <pendejoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:49:49 by pendejoo          #+#    #+#             */
/*   Updated: 2023/05/31 21:47:11 by pendejoo         ###   ########.fr       */
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

char *parse_init(int argc, char **argv)
{
    int     map_to_open;
    char    *map_to_parse;
    char    **map_tab;
    int i;

    i = 0;
    map_to_parse = NULL;
    map_to_open = open(argv[1], O_RDONLY, 0777);
    if (map_to_open == -1)
        err_msg(2);
    if (check_extension(argv[1]) == 0)
        err_msg(1);
    while (1)
    {
        map_to_parse = get_next_line(map_to_open);
        *map_tab = ft_strdup(map_to_parse);
        i++;
        if (map_to_parse == NULL)
            break;
    }
    return (map_to_parse);
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
        return (1);
    return (0);
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