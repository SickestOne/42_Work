/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:29:39 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/05 14:14:24 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
  pid_t          pid;

  if ((pid = fork()) == -1)
    {
      perror("fork");
      return 1;
    }
  else if (pid == 0)
    printf("Je suis le fils, et mon pid = %d\n", getpid());
  else
    printf("Je suis le pere, et mon pid = %d. Le pid de mon fils = %d\n", getpid(), pid);

  return 0;
}
