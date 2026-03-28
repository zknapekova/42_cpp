/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:23 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/28 15:58:41 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria(std::string const &type): _type(type)
{ 
	std::cout << "AMateria parametrized constructor\n";
}


AMateria::AMateria(): _type("None")
{
	std::cout << "AMateria default constructor\n";
}


AMateria::~AMateria()
{ 
	std::cout << "AMateria destructor\n";
}


AMateria::AMateria(const AMateria& orig):
	_type(orig._type)
{
	std::cout << "AMateria copy constructor\n";
}

AMateria& AMateria::operator=(const AMateria& orig)
{
	std::cout << "AMateria assignment operator\n";
	if (&orig != this)
		_type = orig._type;

	return *this;
}

std::string const & AMateria::getType() const
{
	return _type;
}






