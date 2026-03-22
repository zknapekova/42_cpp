/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:40:01 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/22 16:48:16 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main( void ) 
{
	//default constructor:
	std::cout << "## Default constructor ##" << std::endl;
	ClapTrap a;
	std::cout << a << std::endl;
	
	//parametrized constructor:
	std::cout << "\n ## Parametrized constructor ##" << std::endl;
	ClapTrap b (ClapTrap("Beta"));
	std::cout << b << std::endl;

	std::cout << "\n## Examples of attacking, taking damage, repairing ## " << std::endl;
	a.attack("Beta");
	b.takeDamage(5);
	b.beRepaired(2);
	std::cout << b << std::endl;
	
	std::cout << "\n ## Assignment operator example ##" << std::endl;
	a = b;
	std::cout << b << std::endl;
	
	std::cout << "\n ## Copy constructor example ##" << std::endl;
	ClapTrap c (a);
	std::cout << c << std::endl;
	
	std::cout << "\n## Example of taking bigger damage than number of hit points ##" << std::endl;
	b.takeDamage(4294);
	b.takeDamage(50);
	
	return 0;
}
