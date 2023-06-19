#include "philo.h"

int	main(int ac, char **av)
{
	if (ac >= 5 && ac <= 6)
	{
		if (check_args(av))
			printf("Let's go\n");
		else
		{
			printf("Error\nCheck your input.\n");
			return (0);
		}
	}
	else
		print_errors();
	return (0);
}

int	check_args(char **av)
{
	if (!letter_checker(av) || !int_checker(av))
		return (0);
	return (1);
}