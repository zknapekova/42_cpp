#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	std::string name;
	Weapon		*weapon = NULL;
	
	public:
		HumanB(std::string name_);
		void attack( void );
		void setWeapon(Weapon &weapon_);
};

#endif
