/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:26:25 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/08 18:56:18 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *go)
{
	static int	coll;

	coll = get_collect(clone_map(go->map));
	if (go->map[go->p_y - 1][go->p_x] == '1')
		return ;
	else if (go->map[go->p_y - 1][go->p_x] == 'F')
		lose_msg(go);
	go->p_y -= 1;
	go->player->instances[0].y -= 64;
	if (go->map[go->p_y][go->p_x] == 'C')
	{
		mlx_delete_image(go->mlx, go->player);
		aff_texture(go, go->p_x, go->p_y, "./assets/textures/flr.png");
		init_player(go, 1);
		go->map[go->p_y][go->p_x] = '0';
	}
	if (go->map[go->p_y][go->p_x] == 'E' && coll == 0)
	{
		free_tabs(go->map);
		free(go);
		win_msg();
	}
	go->steps++;
	dis_steps(go);
}

void	move_down(t_game *go)
{
	static int	coll;

	coll = get_collect(clone_map(go->map));
	if (go->map[go->p_y + 1][go->p_x] == '1')
		return ;
	else if (go->map[go->p_y + 1][go->p_x] == 'F')
		lose_msg(go);
	go->p_y += 1;
	go->player->instances[0].y += 64;
	if (go->map[go->p_y][go->p_x] == 'C')
	{
		mlx_delete_image(go->mlx, go->player);
		aff_texture(go, go->p_x, go->p_y, "./assets/textures/flr.png");
		init_player(go, 1);
		go->map[go->p_y][go->p_x] = '0';
	}
	if (go->map[go->p_y][go->p_x] == 'E' && coll == 0)
	{
		free_tabs(go->map);
		free(go);
		win_msg();
	}
	go->steps++;
	dis_steps(go);
}

void	move_right(t_game *go)
{
	static int	coll;

	coll = get_collect(clone_map(go->map));
	mlx_delete_image(go->mlx, go->player);
	init_player(go, 1);
	if (go->map[go->p_y][go->p_x + 1] == '1')
		return ;
	else if (go->map[go->p_y][go->p_x + 1] == 'F')
		lose_msg(go);
	go->p_x += 1;
	go->player->instances[0].x += 64;
	if (go->map[go->p_y][go->p_x] == 'C')
	{
		aff_texture(go, go->p_x, go->p_y, "./assets/textures/flr.png");
		init_player(go, 1);
		go->map[go->p_y][go->p_x] = '0';
	}
	if (go->map[go->p_y][go->p_x] == 'E' && coll == 0)
	{
		free_tabs(go->map);
		free(go);
		win_msg();
	}
	go->steps++;
	dis_steps(go);
}

void	move_left(t_game *go)
{
	static int	coll;

	coll = get_collect(clone_map(go->map));
	mlx_delete_image(go->mlx, go->player);
	init_player(go, 2);
	if (go->map[go->p_y][go->p_x - 1] == '1')
		return ;
	else if (go->map[go->p_y][go->p_x - 1] == 'F')
		lose_msg(go);
	go->p_x -= 1;
	go->player->instances[0].x -= 64;
	if (go->map[go->p_y][go->p_x] == 'C')
	{
		aff_texture(go, go->p_x, go->p_y, "./assets/textures/flr.png");
		init_player(go, 2);
		go->map[go->p_y][go->p_x] = '0';
	}
	if (go->map[go->p_y][go->p_x] == 'E' && coll == 0)
	{
		free_tabs(go->map);
		free(go);
		win_msg();
	}
	go->steps++;
	dis_steps(go);
}

void	dis_steps(t_game *go)
{
	char	*number;

	number = NULL;
	mlx_delete_image(go->mlx, go->c_step);
	number = ft_itoa(go->steps);
	go->c_step = mlx_put_string(go->mlx, number, go->m_x, go->m_y);
	free(number);
}
