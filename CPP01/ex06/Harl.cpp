/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:10:25 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:10:25 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{ }

void Harl::complain( std::string level )
{
		
	Level level_en;
	int	i = 0;	

	std::string lvl_arr[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	while (i < 4 && level != lvl_arr[i])
	{
		i++;
	}
	level_en = static_cast<Level>(i);
	switch (level_en)
	{
		case DEBUG :
			this->debug();
		case INFO :
			this->info();
		case WARNING :
			this->warning();
		case ERROR:
			this->error();
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
