/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:01 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/07 13:28:05 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mlx_is_key_down()

#include "../so_long.h"

void	key(mlx_key_data_t keydata, void *param)
{
	t_game	*go;

	go = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_putsterr("See you around the world\n");
		exit(EXIT_SUCCESS);
	}
	else if (mlx_is_key_down(go->mlx, MLX_KEY_W))
		move_up(go);
	else if (mlx_is_key_down(go->mlx, MLX_KEY_S))
		move_down(go);
	else if (mlx_is_key_down(go->mlx, MLX_KEY_D))
		move_right(go);
	else if (mlx_is_key_down(go->mlx, MLX_KEY_A))
		move_left(go);
}

void	init_player(t_game *p, int i)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (i == 1)
		texture = mlx_load_png("assets/textures/Charlie_R.png");
	else if (i == 2)
		texture = mlx_load_png("assets/textures/Charlie_L.png");
	p->player = mlx_texture_to_image(p->mlx, texture);
	mlx_image_to_window(p->mlx, p->player, p->p_x * 64, p->p_y * 64);
}