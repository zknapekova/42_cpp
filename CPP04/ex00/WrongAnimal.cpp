#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void): _type("RandomWrongAnimal")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal parametrized constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& orig):
	_type(orig._type)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& orig)
{
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	
	if (this != &orig)
		_type = orig._type;
	return *this;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "*random WrongAnimal sound*" << std::endl;
}


std::string	WrongAnimal::getType( void ) const
{
	return _type;
}
	
