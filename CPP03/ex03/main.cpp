/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:40:01 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/22 17:01:49 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) 
{
	//default constructor:
	std::cout << "## Default constructor example ##" << std::endl;
	DiamondTrap a;
	std::cout <<  a << std::endl;
	a.whoAmI();
	
	//parametrized constructor:
	std::cout << "\n## Parametrized constructor example ##" << std::endl;
	DiamondTrap b = DiamondTrap("Beta");
	b.whoAmI();
	
	std::cout << "\n## Examples of attack, taking damage and repairing ## " << std::endl;
	b.attack("Gamma");
	b.takeDamage(5);
	b.beRepaired(2);
	
	std::cout << "\nShow status" << std::endl;
	std::cout << b << std::endl;
	
	//amount is larger than number of hit points
	std::cout << "\n## Example of taking bigger damage than number of hit points ##" << std::endl;
	b.takeDamage(150);
	
	std::cout << "\n## Attack with zero hit points  ##" << std::endl;
	b.attack("Gamma");
	
	std::cout << "\n## Repair with zero hit points  ##" << std::endl;
	b.beRepaired(20);
	
	//assignment operator
	std::cout << "\n## Assignment operator example ##" << std::endl;
	std::cout << "Before assigning: " << a << std::endl;
	std::cout << b << std::endl;
	a = b;
	std::cout << "After assigning: " << a << std::endl;
	
	//copy constructor
	std::cout << "\n## Copy constructor example ##" << std::endl;
	DiamondTrap c (b);
	std::cout << c << std::endl << std::endl;
	
	//attack method: slicing
	std::cout << "\n ## Example of slicing: " << std::endl;
	ClapTrap ct;
	ct = b;
	ct.attack("Gamma");
	
	//attack method: correct behavior
	std::cout << "\n ## Correct: " << std::endl;
	ClapTrap *p_ct = new DiamondTrap("Gamma");
	p_ct->attack("Beta");
	delete p_ct;
	
	std::cout << "\n ## Assigning reference: " << std::endl;
	ClapTrap *p_ct2 = &c;
	p_ct2->attack("Delta");
		
	return 0;
}
