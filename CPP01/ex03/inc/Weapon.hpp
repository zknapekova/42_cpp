#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon 
{
	std::string type;
	
	public:
		Weapon(std::string type_);
		void setType(std::string new_type);
		const std::string& getType( void );

};

#endif
