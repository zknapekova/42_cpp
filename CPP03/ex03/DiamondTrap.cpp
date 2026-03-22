/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:32:52 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/22 17:44:46 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ):
	ClapTrap("_clap_name"),
	FragTrap(),
	ScavTrap(),
	_name("None")
{
    _hit_points = FragTrap::ft_default_hit_points;
    _energy_points = ScavTrap::st_default_energy_points;
    _attack_damage = FragTrap::ft_default_attack_damage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ):
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	_name(name)
{
    _hit_points = FragTrap::ft_default_hit_points;
    _energy_points = ScavTrap::st_default_energy_points;
    _attack_damage = FragTrap::ft_default_attack_damage;
	std::cout << "DiamondTrap parametrized constructor called" << std::endl;
}


DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}


DiamondTrap::DiamondTrap( const DiamondTrap& orig ):
	ClapTrap(orig),
	FragTrap(orig),
	ScavTrap(orig)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& orig)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &orig)
		ClapTrap::operator=(orig);
	return *this;	
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " \
	<<  ClapTrap::_name << std::endl; 
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

