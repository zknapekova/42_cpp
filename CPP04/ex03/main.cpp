/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:38 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 19:11:14 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

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
	bob->unequip(0);
	bob->unequip(1);
	bob->unequip(2);
	bob->unequip(3);
	bob->equip(cure_clone);
		
	Character orig = Character("orig");
	orig.equip(new Ice());
	Character copy(orig);
	
	AMateria *test_cp1 = copy.getAMateria(0);
	AMateria *test_cp2 = orig.getAMateria(0);
	test_comp(test_cp1 == test_cp2, false, "Test Character copy constructor (deep copy)");
	delete test_cp1;
	
	Character assign(orig);
	assign = orig;
	AMateria *test_cp3 = assign.getAMateria(0);
	test_comp(test_cp3 == test_cp2, false, "Test Character assignment operator (deep copy)");
	delete test_cp2;
	delete test_cp3;
	
	//Subject's main
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob2 = new Character("bob");
	me->use(0, *bob2);
	me->use(1, *bob2);
	delete bob2;
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
