#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*start;

	start = malloc(sizeof(t_args));
	if (!start)
		return (printf("Malloc error\n"), 0);
	if (ac >= 5 && ac <= 6)
	{
		if (check_args(av))
		{
			args_init(start, ac, av);
		}
		else
			return (print_errors(), 0);
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