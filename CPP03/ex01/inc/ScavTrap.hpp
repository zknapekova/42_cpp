#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	static const int	st_default_hit_points = 100;
	static const int	st_default_energy_points = 50;
	static const int	st_default_attack_damage = 20;
	
	
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& orig );
		ScavTrap& operator=(const ScavTrap& orig);
		~ScavTrap( void );
		
		void	attack(const std::string& target); //override (in C++ 11)
		void	guardGate();
};



#endif
