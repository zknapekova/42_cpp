/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:14:43 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:14:43 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): 
	Animal("Dog")
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog& orig):
	Animal(orig)
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& orig)
{
	std::cout << "Dog copy assignment operator" << std::endl;
	
	if (this != &orig)
		Animal::operator=(orig);
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "bark" << std:: endl;
}
