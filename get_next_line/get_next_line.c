/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:22:46 by rvan-den          #+#    #+#             */
/*   Updated: 2023/01/18 22:55:38 by pendejoo         ###   ########.fr       */
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
	free(s1);
	s1 = NULL;
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
 * fix this
 * Coder apres bouffer ca marche pas fdp
 * Rappel pour quand tu retouchera ce tas de merde fumant (ton code) :
 * - t'a reussi a isoler le \n jusquau \0.
 * - Demmerde toi.
 * - Que celui qui stalk mon github en se foutant de ma gueule choppe le sida.
 * - Elias pue.
 * - ?? Utilise la partie count_words modifiee de ton ft_split (\n search) ??
 */
char	*cropped_return(char *temp)
{
	int i;
	int j;
	char *hold;
	char *result;
	char *dest;

	i = 0;
	j = 0;
	hold = malloc((sizeof(temp)));
	if (!hold)
		return (NULL);
	while (temp[i] || hold[j])
	{
		if (temp[i] == '\n')
		{
			hold = &temp[i]; // hold prend bien la valeur.
			while (hold[j])
				j++;
		}
		i++;
	}
	dest = malloc((sizeof(char *)));    // marche pas
	dest = &temp[i + 1] - hold[j];      // encore moins
	free(hold);
	return (dest);                      
	//return (&temp[i + 1]);
}

char	*get_next_line(int fd)
{
	size_t ret;
	char *buf;
	char *temp;

	temp = NULL;
	buf = malloc((sizeof(char *) * (BUFFER_SIZE + 1)));
	ret = read(fd, buf, BUFFER_SIZE);	
	buf[ret] = '\0';
	while ((ret <= BUFFER_SIZE && is_return(temp) != 1))
	{
		temp = ft_strjoin(temp, buf);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	temp = cropped_return(temp);
	return (temp);
}

