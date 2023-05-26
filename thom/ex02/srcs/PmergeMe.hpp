/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:25:54 by tvanbael          #+#    #+#             */
/*   Updated: 2023/05/21 21:25:56 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <chrono>

bool check_numbers(const std::string &s);
void guru_meditation(int err);
void print_container(std::list<int> list, std::vector<int> vector);

template <typename T>
void push_numbers(char **argv, T *container)
{
	for (int i = 1; argv[i]; i++)
	{
		if (!check_numbers(argv[i]))
			guru_meditation(1);
		if (std::atoi(argv[i]) < 0)
			guru_meditation(2);
		container->push_back(std::atoi(argv[i]));
	}
}

template <typename T>
void merge_container(T *left, T *right, T *container)
{
	typename T::iterator it_left = left->begin();
	typename T::iterator it_right = right->begin();
	while (it_left != left->end() && it_right != right->end())
	{
		if (*it_left < *it_right)
		{
			container->push_back(*it_left);
			it_left++;
		}
		else
		{
			container->push_back(*it_right);
			it_right++;
		}
	}
	while (it_left != left->end())
	{
		container->push_back(*it_left);
		it_left++;
	}
	while (it_right != right->end())
	{
		container->push_back(*it_right);
		it_right++;
	}
}

template <typename T>
void mergesort(T *container)
{
	if (container->size() <= 1)
		return ;
	typename T::iterator middle = container->begin();
	std::advance(middle, container->size() / 2);
	T left(container->begin(), middle);
	T right(middle, container->end());
	mergesort(&left);
	mergesort(&right);
	container->clear();
	::merge_container(&left, &right, container);
}

#endif
