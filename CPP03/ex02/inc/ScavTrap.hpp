/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:34:23 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/21 13:34:23 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		
		void	attack(const std::string& target);
		void	guardGate();
};



#endif
