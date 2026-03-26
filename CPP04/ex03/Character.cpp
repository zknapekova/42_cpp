#include "Character.hpp"


Character::Character():_name("None")
{
	std::cout << "Character default constructor\n";
	for (size_t i = 0; i < 4; i++)
    	_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character parametrized constructor\n";
	for (size_t i = 0; i < 4; i++)
    	_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor\n";
	for (size_t i = 0; i < 4; i++)
	{
    	if (_inventory[i])
    		delete _inventory[i];
    }
}



std::string const & getName() const
{
	return _name;
}
