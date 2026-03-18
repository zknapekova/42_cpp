/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:54:30 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/17 16:54:33 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	static const int	default_hit_points = 10;
	static const int	default_energy_points = 10;
	static const int	default_attack_damage = 0;
	
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	
	public:
		ClapTrap( void);
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap&  orig);
		ClapTrap& operator=(const ClapTrap& orig);
		~ClapTrap( void );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string 	getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;
		unsigned int	getEnergyPoints( void ) const;

};

std::ostream& operator<<( std::ostream& outs, const ClapTrap& ct );


#endif
