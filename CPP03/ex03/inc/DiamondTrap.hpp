/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:33:25 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/21 15:42:42 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& orig );
		DiamondTrap& operator=(const DiamondTrap& orig);
		~DiamondTrap();
		
		void 	whoAmI( void );
		void	attack(const std::string& target);
};



#endif
