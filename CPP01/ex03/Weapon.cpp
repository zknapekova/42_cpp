/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:08:36 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:15:57 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type_): type(type_)
{ }

void Weapon::setType(std::string new_type)
{
	type = new_type;
}

const std::string &Weapon::getType( void )
{
	//compiler converts it to reference
	return type;
}



