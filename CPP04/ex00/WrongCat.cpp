/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:14:31 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:14:31 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):
	WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& orig):
	WrongAnimal(orig)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& orig)
{
	std::cout << "WrongCat copy assignment operator" << std::endl;
	
	if (this != &orig)
		WrongAnimal::operator=(orig);
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "wrong meow" << std:: endl;
}
