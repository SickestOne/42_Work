#include <stdlib.h>
#include <stdio.h>

int	get_tab_size(int start, int end)
{
	int i = 0;
	int t_start = start;
	if ((start >= 1 && end > 0) || (start <= 0 && end >= 0))
	{
		while (t_start != end)
		{
			t_start++;
			i++;
		}
	}
	else if ((start >= 0 && end <= 0) || (start <= 0 && end <= 0))
	{
		while (t_start != end)
		{
			t_start--;
			i++;
		}
	}
	return (i);
}

int	*ft_range(int start, int end)
{
	int i = 0;
	int t_start = start;
	int tab_size = get_tab_size(start, end);
	int *tab = malloc(sizeof(int) * (tab_size + 1));
	if (!tab)
		return (NULL);
	if (tab_size == 0)
	{
		tab[0] = 0;
		return (tab);
	}
	if ((start >= 1 && end > 0) || (start <= 0 && end >= 0))
	{
		while (i < tab_size + 1)
		{
			tab[i] = t_start;
			t_start++;
			i++;
		}
	}
	else if ((start >= 0 && end <= 0) || (start <= 0 && end <= 0))
	{
		while (i < tab_size + 1)
		{
			tab[i] = t_start;
			t_start--;
			i++;
		}
	}
	return (tab);
}
