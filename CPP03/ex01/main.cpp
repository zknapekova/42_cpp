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
	ScavTrap a;
	ScavTrap b = ScavTrap("Beta");
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	b.attack("Beta");
	b.takeDamage(5);
	b.beRepaired(2);
	b.guardGate();
	std::cout << b << std::endl;
	b.takeDamage(50);
	
	a = b;
	std::cout << b << std::endl;
	
	ScavTrap c (a);
	std::cout << c << std::endl;
	
	return 0;
}
