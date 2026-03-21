/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:34:19 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/21 13:34:19 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
