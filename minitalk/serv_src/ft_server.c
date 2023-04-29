/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:45:33 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/29 12:33:39 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	test(void)
{
	int	pid;

	pid = getpid();
	if (pid < 0)
		exit (1);
	ft_printf("PID : %d\n", pid);
	ft_printf("Usage -> ./client PID string-to-send\n");
	while (1)
		pause();
}

int	main(void)
{
	test();
	return (0);
}
