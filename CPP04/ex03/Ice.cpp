#include "Ice.hpp"

Ice::Ice():
	AMateria("ice")
{
	std::cout << "Ice default constructor\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor\n";
}

Ice::Ice(const Ice &orig):
	AMateria(orig)
{
	std::cout << "Ice copy constructor\n";
}

Ice& Ice::operator=(const Ice &orig)
{
	std::cout << "Ice assignment operator\n";
	if (this != &orig)
		AMateria::operator=(orig);
	return *this;
}

Ice* Ice::clone() const
{
	Ice *cloned = new Ice(*this);	
	return cloned;
}

