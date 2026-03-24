#include "AAnimal.hpp"


AAnimal::AAnimal(void): _type("RandomAAnimal")
{
	std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	std::cout << "AAnimal parametrized constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& orig):
	_type(orig._type)
{
	std::cout << "AAnimal copy constructor" << std::endl;
}


AAnimal& AAnimal::operator=(const AAnimal& orig)
{
	std::cout << "AAnimal copy assignment operator" << std::endl;
	
	if (this != &orig)
		_type = orig._type;
	return *this;
}


std::string	AAnimal::getType( void ) const
{
	return _type;
}
	

