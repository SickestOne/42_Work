#include <unistd.h>

void	alpha_mirror(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = 90 - str[i] + 65;
		else if (str[i] >= 97 && str[i] <= 122)
			str[i] = 122 - str[i] + 97;
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	alpha_mirror(av[1]);
	write (1, "\n", 1);
	return (0);
}
