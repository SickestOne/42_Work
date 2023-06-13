#include <unistd.h>

int	find_al(char c)
{
	int i = 1;
	char z = 'a';
	char Z = 'A';
	if (c >= 'a' && c <= 'z')
	{
		while (z != c)
		{
			z++;
			i++;
		}
		return (i);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		while (Z != c)
		{
			Z++;
			i++;
		}
		return (i);
	}
	return (0);
}

void	repeat_alpha(char *str)
{
	int i = 0;
	while (str[i])
	{
		int c = find_al(str[i]);
		if (c == 0)
			write (1, &str[i], 1);
		while (c > 0)
		{
			write (1, &str[i], 1);
			c--;
		}
		c = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	if  (ac != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	repeat_alpha(av[1]);
	write (1, "\n", 1);
	return (0);
}
