/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Diogo-ss <contact@diogosilva.dev>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:15:20 by Diogo-ss          #+#    #+#             */
/*   Updated: 2023/07/04 13:15:22 by Diogo-ss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pth_alc_err(int i)
{
	if (i == 0)
		printf("Thread ids memory allocations failed !\n");
	if (i == 1)
		printf("Fork memory allocations failed !\n");
	if (i == 2)
		printf("Philosophers memory allocations failed !\n");
}
