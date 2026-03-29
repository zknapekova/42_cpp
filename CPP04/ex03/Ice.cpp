/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:34 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 19:14:13 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():
	AMateria("ice")
{ }

Ice::~Ice()
{ }

Ice::Ice(const Ice &orig):
	AMateria(orig)
{ }

Ice& Ice::operator=(const Ice &orig)
{
	if (this != &orig)
		AMateria::operator=(orig);
	return *this;
}

Ice* Ice::clone() const
{
	Ice *cloned = new Ice(*this);	
	return cloned;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

