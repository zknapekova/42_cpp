/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:54:17 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/17 16:54:20 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name(""),
	_hit_points(default_hit_points),
	_energy_points(default_energy_points),
	_attack_damage(default_attack_damage)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): 
	_name(name),
	_hit_points(default_hit_points),
	_energy_points(default_energy_points),
	_attack_damage(default_attack_damage)
{
	std::cout << "ClapTrap parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& orig): 
	_name(orig._name),
	_hit_points(orig._hit_points),
	_energy_points(orig._energy_points),
	_attack_damage(orig._attack_damage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap &orig)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	
	_name = orig._name;
	_hit_points = orig._hit_points;
	_energy_points = orig._energy_points;
	_attack_damage = orig._attack_damage;
	
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
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

void	ClapTrap::attack(const std::string& target)
{
	if ( _energy_points > 0 )
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << \
target << ", causing " << _attack_damage << " points of damage!\n";
	}
	else
		std::cerr << "Cannot attack. Number of energy points is too low\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ( _hit_points >= amount )
	{
		std::cout << _name << " took damage and lost " << amount << " hit points\n";
		_hit_points -= amount;
	}
	else
		std::cerr << "Cannot subtract attack damage from hit points. Number of hit points is too low\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ( _energy_points > 0 )
	{
		_hit_points += amount;
		_energy_points--;
		std::cout << _name << " repaired and regained " << amount << " hit points\n";
	}
	else
		std::cerr << "Cannot repair. Number of energy points is too low\n";
}


