/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:28:54 by pendejoo          #+#    #+#             */
/*   Updated: 2023/06/05 11:46:17 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    err_msg(int i)
{
    ft_putsterr("Error\n");
    if (i == 1)
    {
        ft_putsterr("Bad file extension, need .ber\n");
        exit(2);
    }
    if (i == 2)
    {
        ft_putsterr("Can't open map.\n");
        exit (2);
    }
    if (i == 3)
    {
        ft_putsterr("Map is not a square.\n");
        exit(2);
    }
    if (i == 4)
    {
        ft_putsterr("Map is not closed. ");
        ft_putsterr("Check the 1 for top and bottom borders\n");
        exit(2);
    }
}

void    err_msg_2(int i)
{
    ft_putsterr("Error\n");
    if (i == 1)
    {
        ft_putsterr("Map doesn't have a good");
        ft_putsterr(" number of collectibles/player/exit.\n");
        ft_putsterr("At least one collectible,");
        ft_putsterr(" just one player, just one exit.\n");
        exit(2);
    }
    if (i == 2)
    {
        ft_putsterr("Map has forbidden characters\n");
        exit(2);
    }
    if (i == 3)
    {
        ft_putsterr("Map is not doable\n");
        exit(2);
    }
}

void    ft_putsterr(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(STDERR_FILENO, &str[i], 1);
}