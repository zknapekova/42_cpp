/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:09:02 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:12:41 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	std::string name;
	Weapon		*weapon;
	
	public:
		HumanB(std::string name_);
		void attack( void );
		void setWeapon(Weapon &weapon_);
};

#endif
