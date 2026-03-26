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
