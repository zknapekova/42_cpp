/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:09:07 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:09:07 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	std::string name;
	Weapon		&weapon;
	
	public:
		HumanA(std::string name_, Weapon &weapon_);
		void attack( void );

};

#endif
