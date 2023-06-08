/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:24:25 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/08 18:55:31 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	struct_init(t_game *init, char **argv)
{
	char	**tmp;

	tmp = fill_map_tab(argv);
	init->map = clone_map(tmp);
	init->collect = 0;
	init->c_step = 0;
	init->steps = 0;
	init->exit = 0;
	init->p_y = gpy(tmp, -1, -1);
	init->p_x = gpx(tmp, -1, -1);
	init->m_y = 0;
	init->m_x = 0;
	free_tabs(tmp);
}

void	aff_texture(t_game *af_map, int x, int y, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(af_map->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(af_map->mlx, img, x * 64, y * 64);
}

void	map_init(t_game *mp, char **map)
{
	if (!mp->map)
		return (free(mp->map));
	while (map[mp->m_y])
	{
		mp->m_x = 0;
		while (map[mp->m_y][mp->m_x])
		{
			if (map[mp->m_y][mp->m_x] == '1')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/BRK.png");
			else if (map[mp->m_y][mp->m_x] == '0')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/flr.png");
			else if (map[mp->m_y][mp->m_x] == 'E')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/exit.png");
			else if (map[mp->m_y][mp->m_x] == 'P')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/flr.png");
			else if (map[mp->m_y][mp->m_x] == 'C')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/col2.png");
			else if (map[mp->m_y][mp->m_x] == 'F')
				aff_texture(mp, mp->m_x, mp->m_y, "./assets/textures/col.png");
			mp->m_x++;
		}
		mp->m_y++;
	}
}

void	win_msg(void)
{
	ft_putstr("##################################\n");
	ft_putstr("#---------WIIIINNEEEEER----------#\n");
	ft_putstr("##################################\n");
	exit(EXIT_SUCCESS);
}
