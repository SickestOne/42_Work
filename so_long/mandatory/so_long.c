/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo <pendejoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:49:49 by pendejoo          #+#    #+#             */
/*   Updated: 2023/06/06 20:18:47 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int32_t main(int argc, char **argv)
{
    t_game *go;
    // char **map;

    // map = fill_map_tab(argv);
    if (argc != 2)
        ft_putsterr("Usage : ./so_long [your_map].ber");
    if (!parse_check(argv))
        exit(2);
    go = malloc(sizeof(t_game));
    if (!go)
        exit(2);
    struct_init(go, argv);
    go->mlx = mlx_init(gmsx(go->map) * 64, gmsy(go->map) * 64, "so_long", true);
    map_init(go, go->map);
    init_play(go);
    mlx_key_hook(go->mlx, key, go);
    mlx_loop(go->mlx);
    mlx_terminate(go->mlx);
    return (0);
}

int parse_init(char **argv)
{
    int     map_to_open;
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

int parse_check(char **argv)
{
    int tab[2];
    char **cl_map;
    char **tmp;

    tmp = fill_map_tab(argv);
    cl_map = clone_map(tmp);
    tab[0] = gpx(tmp, -1, -1);
    tab[1] = gpy(tmp, -1, -1);
    if (!check_map_size(tmp, -1) && !map_is_closed(tmp, -1, -1) &&
        !map_params(tmp, 0, -1, 0) && !map_is_valid(tmp, -1, 0))
            free_tabs(tmp);
    free_tabs(tmp);
    if (!map_way_ok(cl_map, tab[0], tab[1]))
    {
        free_tabs(cl_map);
        err_msg_2(3);
    }
    return (1);
}
