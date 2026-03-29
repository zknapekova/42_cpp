/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:23 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 19:12:24 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria(std::string const &type): _type(type)
{ }


AMateria::AMateria(): _type("None")
{ }


AMateria::~AMateria()
{ }


AMateria::AMateria(const AMateria& orig):
	_type(orig._type)
{ }

AMateria& AMateria::operator=(const AMateria& orig)
{
	if (&orig != this)
		_type = orig._type;

	return *this;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{ 
	(void)target;
}






