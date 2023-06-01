/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:28:54 by pendejoo          #+#    #+#             */
/*   Updated: 2023/06/01 11:52:43 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    err_msg(int i)
{
    if (i == 1)
    {
        ft_putsterr("Error\n");
        ft_putsterr("Bad file extension, need .ber\n");
        exit(2);
    }
    if (i == 2)
    {
        ft_putsterr("Error\n");
        ft_putsterr("can't open map\n");
        exit (2);
    }
}

void    ft_putsterr(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(STDERR_FILENO, &str[i], 1);
}