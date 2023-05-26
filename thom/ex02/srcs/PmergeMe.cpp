/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:26:03 by tvanbael          #+#    #+#             */
/*   Updated: 2023/05/21 21:26:05 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool check_numbers(const std::string &s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (std::isdigit(s[i]) == 0)
			return false;
		i++;
	}
	return true;
}

void guru_meditation(int err)
{
	std::cout << "Error : ";
	switch (err)
	{
		case 1:
			std::cout << "Not a number" << std::endl;
			break;
		case 2:
			std::cout << "Not a positive number" << std::endl;
			break;
	}
	exit(err);
}

void print_container(std::list<int> list, std::vector<int> vector)
{
	std::cout << "List : ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Vector : ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
