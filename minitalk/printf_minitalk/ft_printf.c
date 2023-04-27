/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:49:04 by rvan-den          #+#    #+#             */
/*   Updated: 2023/04/27 10:35:35 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_format(va_list ap, const char *fmt, int i, int *len)
{
	if (fmt[i] == 'c')
		*len += ft_do_c(va_arg(ap, int));
	else if (fmt[i] == 's')
		*len += ft_do_s(va_arg(ap, char *));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		*len += ft_putnbr_pf(((long long)va_arg(ap, int)));
	else if (fmt[i] == 'u')
		*len += ft_putnbr_pf(((long long)va_arg(ap, unsigned int)));
	else if (fmt[i] == '%')
		*len += ft_do_c('%');
	else if (fmt[i] == 'x')
		*len += ft_puthex_min((long)va_arg(ap, long long));
	else if (fmt[i] == 'X')
		*len += ft_puthex_maj((long)va_arg(ap, long long));
	else if (fmt[i] == 'p')
		*len += ft_ptradress((long)va_arg(ap, unsigned long long));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, fmt);
	while (fmt[i] && len >= 0)
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_format(ap, fmt, i, &len);
		}
		else
			len += ft_do_c(fmt[i]);
		i++;
	}
	va_end(ap);
	if (len < 0)
		return (-1);
	return (len);
}

/*int	main()
{
	int a = 2500;
	int *ptr = &a;
	ft_printf("L'adresse de a est : %p\n", ptr);
	return (0);
}*/
