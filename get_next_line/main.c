/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:47:35 by rvan-den          #+#    #+#             */
/*   Updated: 2023/01/06 15:32:58 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int	fd;
	int	ret;
	char buf[BUFFER_SIZE + 1];

	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
	ft_putnbr(ret);
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
