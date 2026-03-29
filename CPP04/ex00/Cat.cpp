/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:14:46 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:14:46 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
	Animal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat& orig):
	Animal(orig)
{
	std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& orig)
{
	std::cout << "Cat copy assignment operator" << std::endl;
	
	if (this != &orig)
		Animal::operator=(orig);
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "meow" << std:: endl;
}
