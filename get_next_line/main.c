/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:47:35 by rvan-den          #+#    #+#             */
/*   Updated: 2023/01/20 14:57:21 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    main(void)
{
    int        fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    //while (1)
    //{
      //  line = get_next_line(fd);
        //if (line == NULL)
          //  break;
        //printf("%s", line);
        //if (line)
         //   free(line);
   // }
}
