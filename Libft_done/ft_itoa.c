/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:19:34 by rvan-den          #+#    #+#             */
/*   Updated: 2022/11/23 16:35:02 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	find_sign(int *len, char **dest, int *n, long int *n_cpy)
{
	while (*n_cpy)
	{
		*n_cpy /= 10;
		(*len)++;
	}
	*n_cpy = (long int)*n;
	if (*n <= 0)
		*len += 1;
	*dest = ft_calloc(*len + 1, sizeof(char));
}

char	*ft_itoa(int n)
{
	long int	n_cpy;
	int			len;
	char		*dest;
	int			stop;

	len = 0;
	stop = 0;
	n_cpy = n;
	find_sign(&len, &dest, &n, &n_cpy);
	if (!dest)
		return (NULL);
	if (n == 0)
		dest[0] = '0';
	if (n_cpy < 0)
	{
		stop += 1;
		n_cpy *= -1;
		dest[0] = '-';
	}
	while (len > stop)
	{
		dest[--len] = (n_cpy % 10) + 48;
		n_cpy /= 10;
	}
	return (dest);
}

/*int    main()
{
  printf("%s\n", ft_itoa(-2147483648));
  return (0);
}*/
