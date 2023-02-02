/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:22:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/02 21:56:19 by pendejoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *temp, char *buf)
{
	char	*dest;
	char	*buf_hold;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	if (!temp)
		return (ft_strdup(buf));
	dest = malloc(sizeof(char) * ft_strlen(temp) + ft_strlen(buf) + 1);
	buf_hold = malloc(sizeof(buf));
	if (!buf_hold)
		return (NULL);
	if (!dest)
		return (NULL);
	while (temp[i])
	{
		dest[i] = temp[i];
		i++;
	}
	while (buf[j])
	{
		if (buf[j] == '\n')
			break;
		dest[i] = buf[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	buf = temp;
	return (dest);
}
char	*ft_strdup(char *s1)
{
	char	*dst;
	int		i;
	int		j;

	j = -1;
	i = ft_strlen(s1);
	dst = malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	while (s1[++j])
		dst[j] = s1[j];
	dst[j] = '\0';
	return (dst);
}

size_t	is_return(char *temp)
{
	int	is_true;
	int	i;

	is_true = 0;
	i = 0;
	if (!temp)
		return -1;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			is_true = 1;
			return (1);
		}
		else
			is_true = -1;
		i++;
	}
	return (is_true);
}
/*
 * Find the '\n' and return the line with the '\n'.
 * !! Deletes the first 10 characters of the New line.
 */
char	*cropped_return(char *temp)
{
	int i;
	char *hold;

	i = 0;
	hold = malloc((sizeof(temp)));
	if (!hold || !temp)
		return (NULL);
	while (temp[i])
	{
		hold[i] = temp[i];
		i++;
	}
	temp[i] = hold[i] + '\n';
	free(hold);
	hold = NULL;
	return (&temp[i]);
}

char *crop_buf(char *buf)	
{
	char *holder;
	int o;

	o = 0;

	holder = malloc((sizeof(buf + 1)));
	if (!holder || !buf)
		return (NULL);
	while (buf[o])
	{
		if ((buf[o] == '\n' && buf[o - 1] != '\n') || (buf[o] == '\n' && buf[o + 1] != '\n'))
		{	
			holder = &buf[o + 1];
			break;
		}
		o++;
	}
	buf = holder + '\0';
	holder = NULL;
	free(holder);
	return (buf);
}

/*
 * Fonctionne jusqua un buf_size de 15.
 * A partir de 20, ca patine.
 * Au dela, core dumped.
 */
char	*get_next_line(int fd)
{
	size_t ret;
	static char *buf;
	char *temp;

	temp = NULL;
	if (!buf)
	{
		buf = malloc((sizeof(char *) * (BUFFER_SIZE + 1)));
		ret = read(fd, buf, BUFFER_SIZE);	
		buf[ret] = '\0';
	}
	else
		ret = ft_strlen(buf);

	while (ret > 0)
	{
		temp = ft_strjoin(temp, buf);
		if (is_return(buf) == 1 || is_return(temp) == 1)
		{
			buf = crop_buf(buf);
			break;
		}
		if (is_return(buf) != 1 && is_return(temp) == 1)
			break; // can remove this function ?
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	cropped_return(temp);
	return (temp);
}
