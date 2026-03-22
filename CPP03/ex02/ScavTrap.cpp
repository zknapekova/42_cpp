/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:33:44 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/22 17:44:28 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap( void ):
	ClapTrap()
{
	_hit_points = st_default_hit_points;
	_energy_points = st_default_energy_points;
	_attack_damage = st_default_attack_damage;
	std::cout << "ScavTrap default constructor called" << std::endl;
}


ScavTrap::ScavTrap( std::string name ):
	ClapTrap(name)
{
	_hit_points = st_default_hit_points;
	_energy_points = st_default_energy_points;
	_attack_damage = st_default_attack_damage;
	std::cout << "ScavTrap parametrized constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& orig ):
	ClapTrap(orig)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& orig)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &orig)
		ClapTrap::operator=(orig);
	return *this;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{		
	if ( _energy_points > 0 && _hit_points > 0 )
	{
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << \
target << ", causing " << _attack_damage << " points of damage!\n";
	}
	else if ( _hit_points == 0)
		std::cerr << "ScavTrap " << _name << " cannot attack. Number of hit points is too low\n";
	else
		std::cerr << "ScavTrap " << _name << " cannot attack. Number of energy points is too low\n";
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is in a Gate keeper mode\n";
}



