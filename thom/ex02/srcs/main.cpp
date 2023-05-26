/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:26:09 by tvanbael          #+#    #+#             */
/*   Updated: 2023/05/21 21:26:11 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>

int main(int argc, char **argv)
{
	std::list<int> list;
	std::vector<int> vector;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> time_list, time_vector;

	if (argc < 2)
	{
		std::cout << "Usage : ./PmergeMe <positive integer>" << std::endl;
		return 1;
	}

	::push_numbers(argv, &list);
	::push_numbers(argv, &vector);
	std::cout << "Before sort" << std::endl;
	print_container(list, vector);

	start = std::chrono::system_clock::now();
	::mergesort(&list);
	end = std::chrono::system_clock::now();
	time_list = end - start;

	start = std::chrono::system_clock::now();
	::mergesort(&vector);
	end = std::chrono::system_clock::now();
	time_vector = end - start;


	std::cout << "After sort" << std::endl;
	print_container(list, vector);
	std::cout << "Time for list: " << time_list.count() << "s" << std::endl;
	std::cout << "Time for vector: " << time_vector.count() << "s" << std::endl;

	return 0;
}

