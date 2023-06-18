#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void ft_putstr(char *str)
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
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int count_w(char *str)
{
	int i = 0;
	int wc = 0;
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
	while (str[i] && !issp(str[i]))
		i++;
	char *temp = malloc(sizeof(char) * (i - k + 1));
	if (!temp)
		return (NULL);
	temp[i - k] = '\0';
	j = 0;
	while (k < i)
		temp[j++] = str[k++];
	while (str[i] && issp(str[i]))
		i++;
	return (temp);
}

char **the_split(char *str)
{
	while (*str && issp(*str))
		str++;
	int i = 0;
	int wc = count_w(str);
	char **tab = malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	tab[wc] = 0;
	while (wc != 0)
	{
		tab[i++] = insert_w(str);
		wc--;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	if (ac > 2)
		ft_putstr(av[1]);
	if (ac == 2)
	{
		char **rostr = the_split(av[1]);
		int i = 0;
		while (rostr[i])
		{
			if (i > 0)
			{
				ft_putstr(rostr[i]);
				write (1, " ", 1);
			}
			i++;
		}
		ft_putstr(rostr[0]);
	}
	ft_putstr("\n");
	return (0);
}
