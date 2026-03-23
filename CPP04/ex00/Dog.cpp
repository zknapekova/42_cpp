#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor" << std::endl;
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor constructor" << std::endl;
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
