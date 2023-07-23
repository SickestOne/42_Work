/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-den <rvan-den@student.42mulhouse.fr > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:26:39 by rvan-den          #+#    #+#             */
/*   Updated: 2023/07/23 17:13:57 by rvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	letter_checker(char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (!is_num(av[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_num(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	int_checker(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}


void	print_errors(void)
{
	printf("Error\nInvalid arguments...\n\n");
	printf("You either have too much (>200) philosophers,");
	printf(" 0 philosophers,\na null/negative input in one of the time");
	printf(" arguments, or a forbidden character.\n");
	printf("\nPlease check your input.\n\n");
	printf("Usage ==> ./philo [1] [2] [3] [4] [5](optional)\n");
	printf("[1]  ==> [number of philosophers]\n");
	printf("[2]  ==> [time_to_die] (in milliseconds)\n");
	printf("[3]  ==> [time_to_eat] (in milliseconds)\n");
	printf("[4]  ==> [time_to_sleep] (in milliseconds)\n");
	printf("[5]  ==> [number_of_times_each_philosophers_must_eat]\n");
}

int	check_init(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 6)
		if (ft_atoi(av[5]) <= 0)
			return (0);
	if (ft_atol(av[2]) <= 0 || ft_atol(av[3]) <= 0 ||
		ft_atol(av[4]) <= 0)
		i++;
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) <= 0)
		i++;
	if (i > 0)
		return (0);
	return (1);
}
