#include <stdlib.h>
#include <stdio.h>

int     get_t_size(int start, int end)
{
	int i = 0;
	int	t_start = start;
	int t_end = end;
	if (start < end)
	{
		while (t_start != t_end)
		{
			t_start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (t_start != t_end)
		{
			t_start--;
			i++;
		}
	}
	return (i);
}

int	*ft_rrange(int start, int end)
{
	int i = 0;
	int t_end = end;
	int tab_size = get_t_size(start, end);
	int *tab_f;
	tab_f = malloc(sizeof(int) * (tab_size + 1));
	if (!tab_f)
		return (NULL);
	if (start == end)
	{
		tab_f[0] = start;
		return (tab_f);
	}
	if (start < end)
	{
		while (i < tab_size + 1)
		{
			tab_f[i] = t_end;
			printf("%d\n", tab_f[i]);
			t_end--;
			i++;
		}
	}
	else if (start > end)
	{
		while (i < tab_size + 1)
		{
			tab_f[i] = t_end;
			printf("%d\n", tab_f[i]);
			t_end++;
			i++;
		}
	}
	return (tab_f);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_rrange(atoi(av[1]), atoi(av[2]));
		return (0);
	}
}
