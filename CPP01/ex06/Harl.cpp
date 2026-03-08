/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:10:25 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 16:45:47 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{ }

void Harl::complain( std::string level )
{	
	int	i = 0;	

	std::string lvl_arr[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*ptr[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	while (i < 4 && level != lvl_arr[i])
	{
		i++;
	}
	switch (i)
	{
		case 0 :
			(this->*ptr[0])();
		case 1 :
			(this->*ptr[1])();
		case 2 :
			(this->*ptr[2])();
		case 3 :
			(this->*ptr[3])();
			break;
		default:
			std::cout << "Invalid input\n";
	}

}

void Harl::debug( void )
{
	std::cout << "DEBUG: The program has started" << std::endl;
	
}

void Harl::info( void )
{
	std::cout << "INFO: Connected to DB" << std::endl;

}

void Harl::warning( void )
{
	std::cout << "WARNING: Connection to DB failed. Trying again." << std::endl;

}

void Harl::error( void )
{
	std::cout << "ERROR: Unable to connect to DB." << std::endl;

}
