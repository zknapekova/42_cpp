/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:39:54 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/14 14:39:54 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name(""),
	_hit_points(default_hit_points),
	_energy_points(default_energy_points),
	_attack_damage(default_attack_damage)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): 
	_name(name),
	_hit_points(default_hit_points),
	_energy_points(default_energy_points),
	_attack_damage(default_attack_damage)
{
	std::cout << "Parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& orig): 
	_name(orig._name),
	_hit_points(orig._hit_points),
	_energy_points(orig._energy_points),
	_attack_damage(orig._attack_damage)
{
	std::cout << "Copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap &orig)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	_name = orig._name;
	_hit_points = orig._hit_points;
	_energy_points = orig._energy_points;
	_attack_damage = orig._attack_damage;
	
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}


std::string ClapTrap::getName( void ) const
{
	return _name;

}

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return _hit_points;

}

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return _energy_points;

}

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return _attack_damage;

}


std::ostream& operator<<( std::ostream& outs, const ClapTrap& ct )
{
  outs << "Name: " << ct.getName() << ", Hit points: " << ct.getHitPoints() \
 << ", Energy points: " << ct.getEnergyPoints() << ", Attack damage: " << ct.getAttackDamage();
  return outs;
}




/*
void	ClapTrap::attack(const std::string& target)
{


}

void	ClapTrap::takeDamage(unsigned int amount)
{


}

void	ClapTrap::beRepaired(unsigned int amount)
{


}*/


