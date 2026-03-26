#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	AMateria *_inventory[4];
	std::string	_name;
	
	
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character& orig);
		Character& operator=(const Character& orig);
};


#endif
