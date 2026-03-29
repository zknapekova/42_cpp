/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:30 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 19:13:40 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():
	AMateria("cure")
{ }

Cure::~Cure()
{ }

Cure::Cure(const Cure &orig):
	AMateria(orig)
{ }

Cure& Cure::operator=(const Cure &orig)
{
	if (this != &orig)
		AMateria::operator=(orig);
	return *this;
}

Cure* Cure::clone() const
{
	Cure *cloned = new Cure(*this);	
	return cloned;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds " << std::endl;
}
