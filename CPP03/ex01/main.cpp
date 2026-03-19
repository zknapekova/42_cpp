/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:40:01 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/14 14:40:01 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main( void ) 
{
	//default constructor:
	ScavTrap a;
	std::cout <<  a << std::endl;
	
	//parametrized constructor:
	ScavTrap b = ScavTrap("Beta");
	std::cout << b << std::endl;
	b.attack("Gamma");
	b.takeDamage(5);
	b.beRepaired(2);
	b.guardGate();
	std::cout << b << std::endl;
	
	//amount is larger than number of hit points
	b.takeDamage(150);
	
	//assignment operator
	a = b;
	std::cout << a << std::endl;
	
	//copy constructor
	ScavTrap c (a);
	std::cout << c << std::endl;
	
	//attack method: slicing
	ClapTrap ct;
	ct = b;
	ct.attack("Gamma");
	
	//attack method: correct behavior
	ClapTrap *p_ct = new ScavTrap("Gamma");
	p_ct->attack("Beta");
	delete p_ct;
	
	p_ct = &c;
	p_ct->attack("Delta");
		
	return 0;
}
