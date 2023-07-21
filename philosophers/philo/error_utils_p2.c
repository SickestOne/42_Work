/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:25:23 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/05 16:02:19 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pth_alc_err(int i)
{
	if (i == 0)
		printf("Thread memory allocations failed !\n");
	if (i == 1)
		printf("Fork memory allocations failed !\n");
	if (i == 2)
		printf("Philosophers struct memory allocations failed !\n");
}
