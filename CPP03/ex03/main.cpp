/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:40:01 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/21 15:57:32 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) 
{
	//default constructor:
	DiamondTrap a;
	std::cout <<  a << std::endl;
	
	a.whoAmI();
	//parametrized constructor:
	DiamondTrap b = DiamondTrap("Beta");
	std::cout << b << std::endl;
	b.attack("Gamma");
	b.takeDamage(5);
	b.beRepaired(2);
	b.whoAmI();
	std::cout << b << std::endl;
	
	//amount is larger than number of hit points
	b.takeDamage(150);
	
	//assignment operator
	a = b;
	std::cout << a << std::endl;
	
	//copy constructor
	DiamondTrap c (a);
	std::cout << c << std::endl;
	
	//attack method: slicing
	DiamondTrap ct;
	ct = b;
	ct.attack("Gamma");
	
	//attack method: correct behavior
	DiamondTrap *p_ct = new DiamondTrap("Gamma");
	p_ct->attack("Beta");
	delete p_ct;
	
	p_ct = &c;
	p_ct->attack("Delta");
		
	return 0;
}
