/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den < rvan-den@student.42mulhouse.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:08:34 by rvan-den          #+#    #+#             */
/*   Updated: 2023/05/22 17:15:48 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// modif getenv pour fonction avec le split 
char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(name);
	while (env[i])
	{
		if (ft_strncmp((const char *)env[i], name, j) == 0)
			return (ft_substr((const char *)env[i], 0, j));
		i++;
	}
	return (NULL);
}