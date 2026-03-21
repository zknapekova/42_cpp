#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap: public FragTrap, public ScavTrap
{
	std::string 	_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;
	

	DiamondTrap();
	DiamondTrap( std::string name );
	~DiamondTrap();

}



#endif
