/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pendejoo <pendejoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:26:25 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/06 22:23:41 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *go)
{
	if (go->map[go->p_y - 1][go->p_x] == '1')
		return ;
	go->p_y -= 1;
	go->player->instances[0].y -= 64;
}

void	move_down(t_game *go)
{
	if (go->map[go->p_y + 1][go->p_x] == '1')
		return ;
	go->p_y += 1;
	go->player->instances[0].y += 64;
}

void	move_right(t_game *go)
{
	if (go->map[go->p_y][go->p_x + 1] == '1')
		return ;
	go->p_x += 1;
	go->player->instances[0].x += 64;
}

void	move_left(t_game *go)
{
	if (go->map[go->p_y][go->p_x - 1] == '1')
		return ;
	go->p_x -= 1;
	go->player->instances[0].x -= 64;
}
	