#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	std::string name;
	Weapon		&weapon;
	
	public:
		HumanA(std::string name_, Weapon &weapon_);
		void attack( void );

};

#endif
