/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:24:48 by tvanbael          #+#    #+#             */
/*   Updated: 2023/05/21 21:24:51 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> _stack_numbers;
		int _elem_count;
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN &operator=(const RPN &copy);
		void push_numbers(int n);
		int pop_numbers();
		int get_count();
		void calc(std::string args);
};

#endif
