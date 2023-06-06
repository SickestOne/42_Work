/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:24:25 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/06 17:03:55 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	struct_init(t_game *init, char **argv)
{
	init->map = clone_map(fill_map_tab(argv));
	init->collect = 0;
	init->exit = 0;
	init->p_y = gpy(fill_map_tab(argv), -1, -1);
	init->p_x = gpx(fill_map_tab(argv), -1, -1);
	init->m_y = 0;
	init->m_x = 0;
}

void	aff_texture(t_game *af_map, int x, int y, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(af_map->mlx, texture);
	mlx_image_to_window(af_map->mlx, img, x * 64, y * 64);
}

void	map_init(t_game *mp, char **map)
{
	while (map[mp->m_y])
	{
		mp->m_x = 0;
		while (map[mp->m_y][mp->m_x])
		{
			if (map[mp->m_y][mp->m_x] == '1')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/BRICK_3A.png");
			else if (map[mp->m_y][mp->m_x] == '0')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/floor.png");
			else if (map[mp->m_y][mp->m_x] == 'E')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/exit.png");
			else if (map[mp->m_y][mp->m_x] == 'P')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/floor.png");
			else if (map[mp->m_y][mp->m_x] == 'C')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/Collectible.png");
			mp->m_x++;	
		}
		mp->m_y++;
	}
}
