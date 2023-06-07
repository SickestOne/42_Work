/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:19:34 by rvan-den          #+#    #+#             */
/*   Updated: 2023/06/07 09:56:35 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(size * count);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = s;
	while (i < n)
	{
		*s_cpy = 0;
		s_cpy++;
		i++;
	}
}
/*int    main()
{
  printf("%s\n", ft_itoa(-2147483648));
  return (0);
}*/
