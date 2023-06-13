#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	pgcd(char **av)
{
	int par_one = atoi(av[1]);
	int par_two = atoi(av[2]);
	if (par_one <= 0 || par_two <= 0)
	{
		printf("\n");
		return ;
	}
	while (par_two != 0)
	{
		int temp = par_two;
		par_two = par_one % par_two;
		par_one = temp;
	}
	printf("%d\n", par_one);
	return ;
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	pgcd(av);
	return (0);
}
