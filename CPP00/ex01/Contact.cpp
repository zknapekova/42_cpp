/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:09:29 by zuknapek          #+#    #+#             */
/*   Updated: 2026/02/22 18:15:32 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, \
std::string nickname, std::string phone_number, std::string darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;		
}

Contact::Contact() {
    _first_name = "";
    _last_name = "";
    _nickname = "";
    _phone_number = "";
    _darkest_secret = "";
}

void	Contact::print_var(std::string var)
{
	if (var.size() <= 10)
	{
		std::string spaces (10 - var.size(), ' ');
		std::cout << spaces << var;
	}	
	else
		std::cout<<var.substr(0, 9) << '.';
	std::cout << '|';
}

void	Contact::print_contact()
{
	print_var(_first_name);
	print_var(_last_name);
	print_var(_nickname);
	std::cout << std::endl;
}
