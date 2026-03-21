#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
	static const int	ft_default_hit_points = 100;
	static const int	ft_default_energy_points = 100;
	static const int	ft_default_attack_damage = 30;
	
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& orig );
		FragTrap& operator=(const FragTrap& orig);
		~FragTrap( void );
		
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};



#endif
