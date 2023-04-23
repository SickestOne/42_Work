/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:13:33 by rvan-den          #+#    #+#             */
/*   Updated: 2022/12/14 16:23:47 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_all(char **tab, size_t indice)
{
	size_t	y;

	y = 0;
	while (y <= indice)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i + 1])
	{
		if ((s[i] == c && s[i + 1] != c) || (s[i] != c && i == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*insert_s(char const *s, char c, int next_w)
{
	int		j;
	size_t	i;
	char	*new_tab;

	i = 0;
	while (next_w--)
	{
		j = 0;
		while (s[i] == c && ft_strlen(s) > i)
			i++;
		while (s[i] != c && ft_strlen(s) > i)
		{
			i++;
			j++;
		}
	}
	new_tab = malloc(sizeof(char) * (j + 1));
	if (!new_tab)
		return (NULL);
	i = i - j;
	j = 0;
	while (s[i] != c && ft_strlen(s) > i)
		new_tab[j++] = s[i++];
	new_tab[j] = '\0';
	return (new_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		next_w;
	int		count_c;

	next_w = 1;
	if (!s)
		return (NULL);
	count_c = count_words(s, c);
	tab = malloc(sizeof(char *) * (count_c + 1));
	if (!tab)
		return (NULL);
	while (count_c--)
	{
		tab[next_w - 1] = insert_s(s, c, next_w);
		if (!tab[next_w - 1])
			return (free_all(tab, next_w - 1));
		next_w++;
	}
	tab[next_w - 1] = NULL;
	return (tab);
}

/*int	main()
{
	char str[] = "Le code c'est drole";
	ft_split(str, ' ');
	return (0);
}*/
