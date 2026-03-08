/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:08:25 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:08:25 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon &weapon_): name(name_), weapon(weapon_)
{ };

void HumanA::attack( void )
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}



