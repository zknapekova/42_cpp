#include "Weapon.hpp"

Weapon::Weapon (std::string type_=""): type(type_)
{ }

void Weapon::setType(std::string new_type)
{
	type = new_type;
}

const std::string &Weapon::getType( void )
{
	//compiler converts it to reference
	return type;
}



