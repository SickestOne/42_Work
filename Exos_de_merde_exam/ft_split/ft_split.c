#include <stdlib.h>
#include <stdio.h>

int	ft_issp(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	word_c(char *str)
{
	int i = 0;
	int wc = 0;
	while (str[i])
	{
		if (!ft_issp(str[i]) && ft_issp(str[i + 1]))
			wc++;
		i++;
	}
	return (wc);
}

char *find_w(char *str)
{
	static int i = 0;
	int j = 0;
	int k = i;
	char *tmp;
	while (!ft_issp(str[i]) && str[i])
		i++;
	tmp = malloc(sizeof(char) * (i - k + 1));
	if (!tmp)
		return (NULL);
	tmp[i - k] = 0;
	j = 0;
	while (k < i)
		tmp[j++] = str[k++];
	while (str[i] && ft_issp(str[i]))
		i++;
	return (tmp);
}

char **ft_split(char *str)
{
	while (*str && ft_issp(*str))
		str++;
	int i = 0;
	int count_c = word_c(str);
	char **tab;
	tab = malloc(sizeof(char *) * (count_c + 1));
	if (!tab)
		return (NULL);
	tab[count_c] = NULL;
	while (count_c != 0)
	{
		tab[i] = find_w(str);
		count_c--;
		i++;
	}
	return (tab);
}

int	main()
{
	char **tab = ft_split("Test de phrase a decouper, pour la mettre dans un tableau de tableau. Ca peut aller loin, tres loin weghw etrgqwer wtqegwy");
	int i = 0;
	while (tab[i])
	{
		printf("tab[%d] : %s\n",i, tab[i]);
		i++;
	}
}