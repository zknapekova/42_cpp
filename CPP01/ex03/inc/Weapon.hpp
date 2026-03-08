/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:09:11 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:15:51 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon 
{
	std::string type;
	
	public:
		Weapon(std::string type_="None");
		void setType(std::string new_type);
		const std::string& getType( void );

};

#endif
