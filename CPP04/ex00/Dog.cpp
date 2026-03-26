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
