/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:34 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/28 15:51:34 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():
	AMateria("ice")
{
	std::cout << "Ice default constructor\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor\n";
}

Ice::Ice(const Ice &orig):
	AMateria(orig)
{
	std::cout << "Ice copy constructor\n";
}

Ice& Ice::operator=(const Ice &orig)
{
	std::cout << "Ice assignment operator\n";
	if (this != &orig)
		AMateria::operator=(orig);
	return *this;
}

Ice* Ice::clone() const
{
	std::cout << "Ice clone method\n";
	Ice *cloned = new Ice(*this);	
	return cloned;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

