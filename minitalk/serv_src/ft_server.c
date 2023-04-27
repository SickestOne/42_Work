/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:45:33 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/27 13:54:07 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	test(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("Usage : ./client [PID] [data-for-server]\n");
}

int	main(void)
{
	test();
	return (0);
}
