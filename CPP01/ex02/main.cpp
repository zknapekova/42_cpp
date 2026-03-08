/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:08:14 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:08:14 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string greet ("HI THIS IS BRAIN");
	std::string *stringPTR (&greet);
	std::string &stringREF (greet);
	
	std::cout << "Memory address of the string variable: " << &greet << std::endl;
	std::cout << "Memory address held by pointer to string: " << stringPTR << std::endl;
	std::cout << "Memory address held by reference to string: " << &stringREF << std::endl;
	
	std::cout << "Value of the string variable: " << greet << std::endl;
	std::cout << "Value pointed to by pointer: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by reference: " << stringREF << std::endl;

}
