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

static void	test_comp(bool res, bool expected, std::string name)
{
	std::cout << "TEST: " << name << ": ";
	if (res == expected)
		std::cout << " PASSED\n";
	else
		std::cout << "FAILED: expected: " << expected << ", got: " << res << std::endl;
}

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
	bob->equip(ice_ex);
	bob->equip(cure_ex);
	bob->equip(ice_clone);
	bob->equip(cure_clone);
	
	Character orig = Character("orig");
	orig.equip(ice_e);
	Character copy(orig);
	
	test_comp(copy.getAMateria(0) == orig.getAMateria(0), false, "Test Character copy consctructor (deep copy): ");
	
	Character assign = Character("assign");
	assign = orig;
	test_comp(assign.getAMateria(0) == orig.getAMateria(0), false, "Test Character assignment operator (deep copy): ");

	return 0;
}
