/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:24:56 by tvanbael          #+#    #+#             */
/*   Updated: 2023/05/21 21:31:31 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN() : _elem_count(0) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		this->_stack_numbers = copy._stack_numbers;
		this->_elem_count = copy._elem_count;
	}
	return (*this);
}

void RPN::push_numbers(int n)
{
	this->_stack_numbers.push(n);
	this->_elem_count++;
}

int RPN::pop_numbers()
{
	int top;

	top = this->_stack_numbers.top();
	this->_stack_numbers.pop();
	this->_elem_count--;
	return (top);
}

int RPN::get_count()
{
	return (this->_elem_count);
}

bool check_operator(std::string s)
{
    if (s == "/")
        return true;
    else if (s == "-")
        return true;
    else if (s == "+")
        return true;
    else if (s == "*")
        return true;
    else
        return false;
}

bool check_number(const std::string& s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (std::isdigit(s[i]) == 0)
            return false;
        i++;
    }
    return true;
}

void error_print(int mode)
{
	switch (mode)
	{
		case 0:
			std::cout << "Error: Too much operators" << std::endl;
			break;
		case 1:
			std::cout << "Error : Can divide by zero" << std::endl;
			break;
		case 2:
			std::cout << "Error : Not a number or an operator" << std::endl;
			break;
		case 3:
			std::cout << "Error : Missing operators, stack isn't empty" << std::endl;
			break;
	}
	exit(1);
}

void RPN::calc(std::string args)
{
    int result;
    std::string current_str;
    std::istringstream getlinestream;
    getlinestream.str(args);
    while (std::getline(getlinestream, current_str, ' '))
    {
		if (check_number(current_str))
			this->push_numbers(std::stoi(current_str));
		else if (check_operator(current_str))
		{
			if (this->get_count() == 1)
				error_print(0);
			result = this->pop_numbers();
			if (current_str == "/")
			{
				if (result > 0)
					result = this->pop_numbers() / result;
				else
					error_print(1);
			}
			else if (current_str == "-")
				result = this->pop_numbers() - result;
			else if (current_str == "+")
				result = this->pop_numbers() + result;
			else if (current_str == "*")
				result = this->pop_numbers() * result;
			this->push_numbers(result);
		}
		else
			error_print(2);
    }
	if (this->get_count() == 1)
		std::cout << result << std::endl;
	else
	{
		error_print(3);
		while (this->get_count() != 0)
			std::cout << this->pop_numbers() << std::endl;
	}
}
