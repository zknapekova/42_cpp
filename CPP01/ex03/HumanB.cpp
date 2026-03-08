/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:08:28 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:12:51 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{ 
	weapon = NULL;
};

void HumanB::attack( void )
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon " <<  std::endl;
}

void HumanB::setWeapon( Weapon &weapon_ )
{
	weapon = &weapon_;
}
