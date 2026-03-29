/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:12:50 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:12:50 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():
	AAnimal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
	_brain = new(std::nothrow) Brain;
	if (!_brain)
    	std::cerr << "Brain allocation failed!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& orig):
	AAnimal(orig)
{
	std::cout << "Cat copy constructor" << std::endl;
	_brain = new(std::nothrow) Brain(*orig._brain);
	if (!_brain)
		std::cerr << "Brain allocation failed!" << std::endl;
}

Cat& Cat::operator=(const Cat& orig)
{
	std::cout << "Cat copy assignment operator" << std::endl;
	
	if (this != &orig)
	{
		AAnimal::operator=(orig);
		delete _brain;
		_brain = new(std::nothrow) Brain(*orig._brain);
		if (!_brain)
			std::cerr << "Brain allocation failed!" << std::endl;
	}
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "meow" << std:: endl;
}


const Brain* Cat::getBrain(void) const
{
	return _brain;
}



