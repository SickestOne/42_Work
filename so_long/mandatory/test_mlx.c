/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:30:06 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 18:22:33 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../so_long.h"

#define WIDTH 512
#define HEIGHT 512

// Print the window width and height.
void	mlx_test(void)
{
	
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(2);

	mlx_texture_t* texture = mlx_load_png("./assets/textures/BRICK_3A.png");
	if (!texture)
        exit(2);
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
		exit(2);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(2);

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return ;
}