#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ):
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	std::cout << "DiamondTrap parametrized constructor called" << std::endl;
}


DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
