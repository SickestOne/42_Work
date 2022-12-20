/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:49:18 by rvan-den          #+#    #+#             */
/*   Updated: 2022/12/19 14:48:56 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdio.h>

int		ft_printf(const char *fmt, ...);
int		ft_do_c(int c);
int		ft_do_s(char *str);
int		ft_putnbr_pf(long long nb);
int		ft_puthex_min(unsigned int nb);
int		ft_puthex_maj(unsigned int nb);
int		ft_ptradress(unsigned long long ptr);

#endif
