/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:23:06 by tvanbael          #+#    #+#             */
/*   Updated: 2023/05/21 22:02:53 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <exception>
#include <sstream>

void error_print(std::string err)
{
	std::cout << err << std::endl;
	exit(0);
}

void print_data(std::multimap<std::string, std::string> data)
{
	for (std::multimap<std::string, std::string>::iterator it = data.begin(); it != data.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

bool bisextile(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	return false;
}

bool check_date(std::string date)
{
	std::istringstream ss;
	std::string year, month, day;

	ss.str(date);
	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day, '-');
	if (std::stoi(year) < 2009)
		return false;
	if (std::stoi(year) == 2009 && stoi(month) == 1 && stoi(day) < 2)
	if (std::stoi(month) < 1 || std::stoi(month) > 12)
		return false;
	if (std::stoi(day) < 1 || std::stoi(day) > 31)
		return false;

	if (std::stoi(month) == 2)
	{
		if (bisextile(std::stoi(year)))
			return (std::stoi(day) <= 29);
		else
			return (std::stoi(day) <= 28);
	}

	if (std::stoi(month) == 4 || std::stoi(month) == 6 ||
			std::stoi(month) == 9 || std::stoi(month) == 11)
		return (std::stoi(day) <= 30);
	return true;
}

void BitcoinExchange::get_user_input(char *input)
{
	std::string line;
	std::string date;
	std::string value;

	this->_user_file.open(input);
	if (!this->_user_file.is_open())
		error_print("Error: File not found");
	while (std::getline(this->_user_file, line))
	{
		size_t separatorIndex = line.find('|');
		if (separatorIndex == std::string::npos)
			separatorIndex = line.find(',');

		if (separatorIndex == std::string::npos) {
			std::cerr << "Error: Invalid input format" << std::endl;
			continue;
		}

		date = line.substr(0, separatorIndex);
		value = line.substr(separatorIndex + 1, line.length());
		if (date != "date ")
			this->_user_map.insert(std::make_pair(date, value));
	}
}

bool is_number(const std::string& s)
{
	int i;
	int space_count;

	i = 0;
	space_count = 0;
	while (s[i])
	{
		if ((s[i] >= 48 && s[i] <= 57) || s[i] == '.')
			i++;
		else if (s[i] == '-' && i == 0)
			i++;
		else if (s[i] == ' ')
		{
			space_count++;
			i++;
		}
		else
			return true;
	}
	if (space_count > 1)
		return true;
	return false;
}

void BitcoinExchange::print_value()
{
	std::multimap<std::string, std::string>::iterator it_data;
	std::multimap<std::string, std::string>::iterator it_user;

	for (it_user = this->_user_map.begin(); it_user != this->_user_map.end(); it_user++)
	{
		if (!check_date(it_user->first))
			std::cout << "Error: bad input => " << it_user->first << std::endl;
		else if (it_user->second.empty())
			std::cout << "Error: no value input found" << std::endl;
		else if (is_number(it_user->second))
			std::cout << "Error: not an usable value" << std::endl;
		else
		{
			for (it_data = this->_data_map.begin(); it_data != this->_data_map.end(); it_data++)
			{
				bool cond = false;
				if (it_data->first > it_user->first)
				{
					it_data--;
					cond = true;
				}
				if (it_data->first == it_user->first || cond)
				{
					try
					{
						double data_value = std::stof(it_data->second);
						double user_value = std::stof(it_user->second);
						if (user_value > 1000)
							std::cout << "Error: too large a number." << std::endl;
						else if (user_value < 0)
							std::cout << "Error: not a positive number." << std::endl;
						else
						{
							std::cout.precision(2);
							std::cout << it_user->first << " => " << it_user->second << " = " << std::fixed << data_value * user_value << std::endl;
						}
					}
					catch (std::exception &e)
					{
						std::cout << e.what() << std::endl;
					}
					break;
				}
			}
		}
	}
}

BitcoinExchange::BitcoinExchange()
{
	std::string line;
	std::string date;
	std::string value;

	this->_data_file.open("data.csv");
	if (!this->_data_file.is_open())
		error_print("Error: File not found");
	while (std::getline(this->_data_file, line))
	{
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1, line.length());
		if (date != "date")
			this->_data_map.insert(std::make_pair(date, value));
	}
	// print_data(this->_data_map);
}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	*this = copy;
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & copy)
{
	if (this != &copy)
	{
		this->_data_file << &copy._data_file;
		this->_data_map = copy._data_map;
	}
	return (*this);
}