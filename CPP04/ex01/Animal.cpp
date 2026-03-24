#include "Animal.hpp"


Animal::Animal(void): _type("RandomAnimal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal parametrized constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor constructor" << std::endl;
}

Animal::Animal(const Animal& orig):
	_type(orig._type)
{
	std::cout << "Animal copy constructor" << std::endl;
}


Animal& Animal::operator=(const Animal& orig)
{
	std::cout << "Animal copy assignment operator" << std::endl;
	
	if (this != &orig)
		_type = orig._type;
	return *this;
}

void	Animal::makeSound( void ) const
{
	std::cout << "*random animal sound*" << std::endl;
}


std::string	Animal::getType( void ) const
{
	return _type;
}
	

