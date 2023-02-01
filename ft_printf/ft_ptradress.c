/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptradress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:20:08 by rvan-den          #+#    #+#             */
/*   Updated: 2022/12/24 21:11:54 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_len_ptradr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		count += 1;
	while (ptr)
	{
		ptr /= 16;
		count++;
	}
	return (count + 2);
}

static int	ft_ptr_adr(unsigned long long ptr)
{
	char	*hexa;
	char	*res;
	int		i;
	int		len;

	i = 0;
	hexa = "0123456789abcdef";
	len = count_len_ptradr(ptr);
	res = malloc(sizeof(char) * count_len_ptradr(ptr) + 1);
	if (!res)
		return (-2147483648);
	res[len] = '\0';
	while (len > 2)
	{
		i = ptr % 16;
		ptr = ptr / 16;
		res[--len] = hexa[i];
	}
	res[0] = '0';
	res[1] = 'x';
	i = ft_do_s(res);
	free(res);
	return (i);
}

int	ft_ptradress(unsigned long long ptr)
{
	if (ft_ptr_adr(ptr) < 0)
		return (-2147483648);
	return (count_len_ptradr(ptr));
}
