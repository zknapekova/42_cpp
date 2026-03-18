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

#include "FragTrap.hpp"


int main( void ) 
{
	FragTrap a;
	FragTrap b = FragTrap("Beta");
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	b.attack("Gamma");
	b.takeDamage(5);
	b.beRepaired(2);
	b.highFivesGuys();
	std::cout << b << std::endl;
	b.takeDamage(50);
	
	a = b;
	std::cout << b << std::endl;
	
	FragTrap c (a);
	std::cout << c << std::endl;
	
	return 0;
}
