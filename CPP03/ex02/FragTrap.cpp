/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:33:51 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/22 16:51:56 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ):
	ClapTrap()
{
	_hit_points = ft_default_hit_points;
	_energy_points = ft_default_energy_points;
	_attack_damage = ft_default_attack_damage;
	std::cout << "FragTrap default constructor called" << std::endl;
}


FragTrap::FragTrap( std::string name ):
	ClapTrap(name)
{
	_hit_points = ft_default_hit_points;
	_energy_points = ft_default_energy_points;
	_attack_damage = ft_default_attack_damage;
	std::cout << "FragTrap parametrized constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& orig ):
	ClapTrap(orig)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& orig)
{
	if (this != &orig)
	{
		ClapTrap::operator=(orig);
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	}	
	return *this;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{		
	if ( _energy_points > 0 && _hit_points > 0 )
	{
		_energy_points--;
		std::cout << "FragTrap " << _name << " attacks " << \
target << ", causing " << _attack_damage << " points of damage!\n";
	}
	else if ( _hit_points == 0)
		std::cerr << "FragTrap "<< _name << " cannot attack. Number of hit points is too low\n";
	else
		std::cerr << "FragTrap "<< _name << " cannot attack. Number of energy points is too low\n";
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap requests high-fives\n";
}
