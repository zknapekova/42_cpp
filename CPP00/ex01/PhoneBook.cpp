/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:57:15 by zuknapek          #+#    #+#             */
/*   Updated: 2026/02/22 18:17:10 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>


PhoneBook::PhoneBook()
{
	_count = 0;
	_ind = 0;
}

int	PhoneBook::add_contact()
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
	
	std::cout << "Insert the first name: ";
	std::getline(std::cin, first_name);
	if (first_name.size() == 0)
		return 1;
		
	std::cout << "Insert the last name: ";
	std::getline(std::cin, last_name);
	if (last_name.size() == 0)
		return 1;

	std::cout << "Insert the nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.size() == 0)
		return 1;

	
	std::cout << "Insert the phone number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.size() == 0)
		return 1;
	
	std::cout << "Insert the darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (darkest_secret.size() == 0)
		return 1;
	
	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
	
	arr[_ind] = contact;
	arr_limit_check();
	return 0;
}


void	PhoneBook::arr_limit_check()
{
	if (_count < 8)
		_count++;
	if (_ind < 7)
		_ind++;
	else if (_ind == 7)
		_ind = 0;
}

int PhoneBook::search_contact()
{
	size_t	contact_index;
	std::string	input;
	
	if (_count == 0)
	{
		std::cout << "No contacts added" << std::endl;
		return 1;
	}
	for (size_t i = 0; i < _count; i++)
	{
		std::cout << "         " << i + 1 << '|';   
		arr[i].print_contact();
	}
	while(1)
	{
		std::cout << "Insert the index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cerr << "Error: EOF inserted" << std::endl;
			return 1;
		}
		if (std::cin.fail() || std::cin.bad())
		{
			std::cin.clear();
			continue;
		}
		if (input.size() > 1 || input.size() == 0 || !std::isdigit(input[0]) || input == "0")
		{
			std::cerr << "Error: Incorrect value" << std::endl;
			continue;
		}
		contact_index = input[0] - '0';
	    if (contact_index > _count)
		{
			std::cerr << "Error: Incorrect index" << std::endl;
			continue;
		}
		break;
	}
	std::cout << "         " << contact_index << '|';
	arr[contact_index - 1].print_contact();
	return 0;
}


