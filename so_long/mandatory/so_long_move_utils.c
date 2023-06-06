/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:26:25 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/06 18:15:56 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *go)
{
	go->p_y -= 1;
	go->player->instances[0].y -= 64;
}

void	move_down(t_game *go)
{
	go->p_y += 1;
	go->player->instances[0].y += 64;
}

void	move_right(t_game *go)
{
	go->p_x += 1;
	go->player->instances[0].x += 64;
}

void	move_left(t_game *go)
{
	go->p_x -= 1;
	go->player->instances[0].x -= 64;
}
	