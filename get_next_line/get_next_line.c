/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:22:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/02/01 15:36:45 by rvan-den         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	dest = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free(s1);
	s1 = NULL;
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
	//free(s1);
	//s1 = NULL;
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
		if (temp[i - 1] == '\n')
			break;
		hold[i] = temp[i];
		i++;
	}
	temp[i] = hold[i];
	free(hold);
	hold = NULL;
	return (&temp[i + 1]);
}

char *crop_buf(char *buf)
{
	int h;
	char *cropped_buf;

	h = 0;
	cropped_buf = malloc(sizeof(char) * h + 1);
	if (!cropped_buf)
		return (NULL);
	while (buf[h])
	{
		if (buf[h] != '\n')
			cropped_buf[h] = buf[h];
		h++;
	}
	free(buf);
	buf = cropped_buf;
	return (buf);
}

char	*get_next_line(int fd)
{
	size_t ret;
	static char *buf;
	static char *temp;

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
		if (is_return(buf) == 1 && is_return(temp) == 1)
			crop_buf(buf);
		if (is_return(temp) == 1)
			break;
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	cropped_return(temp);
	return (temp);
}
