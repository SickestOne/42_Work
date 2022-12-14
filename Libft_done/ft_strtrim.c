/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:40:15 by rvan-den          #+#    #+#             */
/*   Updated: 2022/12/15 20:36:20 by babouline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	find_end(char const *s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j]))
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_cpy;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0' || set[0] == '\0')
		return (ft_strdup(s1));
	i = find_start(s1, set);
	j = find_end(s1, set);
	len = j - i + 1;
	s1_cpy = ft_substr(s1, i, len);
	if (!s1_cpy)
		return (NULL);
	return (s1_cpy);
}

/*int	main()
{
	char const s1[] = "adbctestdabc";
	char const set[] = "abcd";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
