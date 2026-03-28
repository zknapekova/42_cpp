/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:38 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/28 18:25:20 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int	main( void )
{
	Ice *ice_ex = new Ice();
	Cure *cure_ex = new Cure();
	
	std::cout << ice_ex->getType() << std::endl;
	std::cout << cure_ex->getType() << std::endl;
	
	Cure *cure_clone = cure_ex->clone();
	Ice *ice_clone = ice_ex->clone();
	
	std::cout << cure_clone->getType() << std::endl;
	std::cout << ice_clone->getType() << std::endl;
	
	//Character class check:
	ICharacter *bob = new Character("bob");
	AMateria *ice_e = new Ice();
	bob->equip(ice_e);
	

	return 0;
}
