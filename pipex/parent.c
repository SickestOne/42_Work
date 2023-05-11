/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:29:39 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/11 17:54:29 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	int	file = open("result.txt", O_WRONLY | O_CREAT, 0777);
	if (file == -1)
		return 2;
	printf ("fd de result.txt : %d\n", file);
	int file2 = dup2(file, STDOUT_FILENO);
	printf ("%d\n", file2);
	return (0);
}
