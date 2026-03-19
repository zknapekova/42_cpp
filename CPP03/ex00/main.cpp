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

#include "ClapTrap.hpp"


int main( void ) 
{
	ClapTrap a;
	std::cout << a << std::endl;
	
	ClapTrap b (ClapTrap("Beta"));
	std::cout << b << std::endl;

	a.attack("Beta");
	b.takeDamage(5);
	b.beRepaired(2);
	std::cout << b << std::endl;
	
	a = b;
	std::cout << b << std::endl;
	
	ClapTrap c (a);
	std::cout << c << std::endl;
	
	b.takeDamage(4294);
	b.takeDamage(50);
	
	return 0;
}
