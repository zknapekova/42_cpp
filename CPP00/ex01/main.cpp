/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:25:31 by zuknapek          #+#    #+#             */
/*   Updated: 2026/02/22 18:00:47 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"


int	main()
{
	std::string cmd;
	PhoneBook phone_book;

	while (1)
	{
		std::cout << "Enter the command ADD, SEARCH or EXIT: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cerr << "Error: EOF inserted" << std::endl;
			break;
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			continue;
		}
		if (cmd == "EXIT")
		{
			std::cout << "Program exited" << std::endl;
			break;
		}
		else if (cmd == "ADD")
		{
			if (phone_book.add_contact() != 0)
			{
				std::cerr << "Error: Contact cannot have an empty field" << std::endl;
				continue;
			}
		}
		else if (cmd == "SEARCH")
		{
			if (phone_book.search_contact() != 0)
				continue;
		}
		else
			std::cerr << "Error: Wrong command" << std::endl;
	
	}	
	return 0;		
}
