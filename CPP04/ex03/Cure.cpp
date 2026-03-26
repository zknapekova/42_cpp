#include "Cure.hpp"

Cure::Cure():
	AMateria("cure")
{
	std::cout << "Cure default constructor\n";
}

Cure::~Cure()
{
	std::cout << "Cure destructor\n";
}

Cure::Cure(const Cure &orig):
	AMateria(orig)
{
	std::cout << "Cure copy constructor\n";
}

Cure& Cure::operator=(const Cure &orig)
{
	std::cout << "Cure assignment operator\n";
	if (this != &orig)
		AMateria::operator=(orig);
	return *this;
}

Cure* Cure::clone() const
{
	Cure *cloned = new Cure(*this);	
	return cloned;
}
