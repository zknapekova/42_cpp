/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:40:01 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/22 16:44:18 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main( void ) 
{
	//default constructor:
	std::cout << "## Default constructor ##" << std::endl;
	ScavTrap a;
	std::cout <<  a << std::endl;
	
	//parametrized constructor:
	std::cout << "\n ## Parametrized constructor ##" << std::endl;
	ScavTrap b = ScavTrap("Beta");
	std::cout << b << std::endl;
	
	std::cout << "\n## Examples of attacking, taking damage, repairing and guarding ## " << std::endl;
	b.attack("Gamma");
	b.takeDamage(5);
	b.beRepaired(2);
	b.guardGate();
	std::cout << b << std::endl;
	
	//amount is larger than number of hit points
	std::cout << "\n## Example of taking bigger damage than number of hit points ##" << std::endl;
	b.takeDamage(150);
	b.beRepaired(2);
	
	//assignment operator
	std::cout << "\n ## Assignment operator example ##" << std::endl;
	std::cout << "Before assigning: " << a << std::endl;
	a = b;
	std::cout << "After assigning: " << a << std::endl;
	
	//copy constructor
	std::cout << "\n ## Copy constructor example ##" << std::endl;
	ScavTrap c (a);
	std::cout << c << std::endl	;
	
	//attack method: slicing
	std::cout << "\n ## Example of slicing: " << std::endl;
	ClapTrap ct;
	ct = b;
	ct.attack("Gamma");
	
	//attack method: correct behavior
	std::cout << "\n ## Correct: " << std::endl;
	ClapTrap *p_ct = new ScavTrap("Gamma");
	p_ct->attack("Beta");
	delete p_ct;
	
	std::cout << "\n ## Assigning reference: " << std::endl;
	ClapTrap *p_ct2  = &a;
	p_ct2->attack("Delta");
		
	return 0;
}
