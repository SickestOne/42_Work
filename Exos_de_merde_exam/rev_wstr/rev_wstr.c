#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	issp(char c)
{
	if (c == ' ' || c == '\t' || c == '\0' || c == '\n')
		return (1);
	return (0);
}

int	count_w(char *str)
{
	int wc = 0;
	int i = 0;
	while (str[i])
	{
		if (!issp(str[i]) && issp(str[i + 1]))
			wc++;
		i++;
	}
	return (wc);
}

char *insert_w(char *str)
{
	static int i = 0;
	int k = i;
	int j = 0;
	char *temp;
	while (str[i] && !issp(str[i]))
		i++;
	temp = malloc(sizeof(char) * (i - k + 1));
	if (!temp)
		return (NULL);
	temp[i - k] = 0;
	j = 0;
	while (k < i)
		temp[j++] = str[k++];
	while (str[i] && issp(str[i]))
		i++;
	return (temp);
}

char **ft_split(char *str)
{
	while (*str && issp(*str))
		str++;
	int i = 0;
	int count = count_w(str);
	char **tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = 0;
	while (count != 0)
	{
		tab[i++] = insert_w(str);
		count--;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		char **tab = ft_split(av[1]);
		while (tab[i])
			i++;
		i--;
		while (i >= 0)
		{
			ft_putstr(tab[i]);
			if (i > 0)
				write (1, " ", 1);
			i--;
		}
	}
	write (1, "\n", 1);
	return (0);
}
