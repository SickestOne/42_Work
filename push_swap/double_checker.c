/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:26:38 by rvan-den          #+#    #+#             */
/*   Updated: 2023/03/08 16:26:40 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* passer data dans ft_atoi tour par tour
* comparer premiere data avec toutes les autres
*   - si aucune data similaire, comparer deuxieme data avec toutes les autres
*   - si doublon detecté, exit(2);
*/
int double_checker(char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
}