/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:38 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 20:22:15 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

static void	test(std::string res, std::string exp, std::string name)
{
	std::cout << "TEST: " << name << ": ";
	if (res == exp)
		std::cout << " PASSED\n";
	else
		std::cout << "FAILED: expected: " << exp << ", got: " << res << std::endl;
}

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
	
	//check if type is set properly
	test(ice_ex->getType(), "ice", "Test type name for Ice object");
	test(cure_ex->getType(), "cure", "Test type name for Cure object");
	
	//check clone functions
	Cure *cure_clone = cure_ex->clone();
	Ice *ice_clone = ice_ex->clone();
	
	test_comp(cure_clone == cure_ex, false, "Test of Cure clone function");
	test_comp(ice_clone == ice_ex, false, "Test of Ice clone function");
	
	// ## Character class check:
	ICharacter *bob = new Character("bob");
	bob->equip(ice_ex);
	bob->equip(cure_ex);
	bob->equip(ice_clone);
	
	std::cout << "\nTest Character::equip: try to equip the same AMateria twice\n";
	bob->equip(ice_clone);
	
	std::cout << "\nTest Character::equip: try to equip more than 4 AMaterias\n";
	bob->equip(cure_clone);
	
	std::cout << "\nTest Character::unequip: unequip the slot 1 and check where new one is placed\n";
	bob->unequip(1);
	bob->equip(cure_clone);
	

	std::cout << "\nTest Character::unequip: use the same index twice\n";
	bob->unequip(2);
	bob->unequip(2);
	
	std::cout << "\nTest Character::unequip: index is out of range\n";
	bob->unequip(100);
	
	std::cout << "\nTest Character::use: message check\n";
	Character orig = Character("orig");
	bob->use(0, orig);
	bob->use(3, orig);
	
	std::cout << "\nTest Character::use: index out of range\n";
	bob->use(100, orig);
	
	// check that Character's copy constructor creates deep copy
	orig.equip(ice_ex);
	Character copy(orig);
	
	AMateria *test_cp1 = copy.getAMateria(0);
	AMateria *test_cp2 = orig.getAMateria(0);
	test_comp(test_cp1 == test_cp2, false, "Test Character copy constructor (deep copy)");
	delete test_cp1;
	
	// check that Character's assignment operator creates deep copy
	Character assign(orig);
	assign = orig;
	AMateria *test_cp3 = assign.getAMateria(0);
	test_comp(test_cp3 == test_cp2, false, "Test Character assignment operator (deep copy)");
	delete test_cp2;
	delete test_cp3;
	
	// ## MateriaSource class check:
	IMateriaSource* src = new MateriaSource();
	
	AMateria *new_Ice = new Ice();
	AMateria *new_Cure = new Cure();
	src->learnMateria(new_Ice);
	src->learnMateria(new_Ice);
	
	std::cout << "\nTest MateriaSource::learnMateria: learn the same Materia multiple times\n";
	src->learnMateria(new_Ice);
	src->learnMateria(new_Ice);
	
	std::cout << "\nTest MateriaSource::learnMateria: try to learn more than 4 Materias\n";
	src->learnMateria(new_Ice);
	
	AMateria* tmp = src->createMateria("cure");
	test_comp(tmp == NULL, true, "Test MateriaSource::createMateria: try to create Materia that is not learned");
	
	std::cout << "\nTest MateriaSource::createMateria: use created AMaterias\n";
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new_Cure);
	src2->learnMateria(new_Ice);
	AMateria* tmp1 = src2->createMateria("cure");
	AMateria* tmp2 = src2->createMateria("ice");
	
	ICharacter* me = new Character("me");
	me->equip(tmp1);
	me->equip(tmp2);
	
	me->use(0, *bob);
	me->use(1, *bob);
	

	delete bob;
	delete me;
	delete src;
	delete src2;
	delete cure_clone;
	delete ice_clone;
	delete ice_ex;
	delete cure_ex;
	delete tmp1;
	delete tmp2;
	delete new_Ice;
	delete new_Cure;
	
	return 0;
}
