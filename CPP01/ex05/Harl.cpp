#include "Harl.hpp"
#include <iostream>

Harl::Harl( void )
{ }

void Harl::complain( std::string level )
{
	std::string lvl_arr[] = { "debug", "info", "warning", "error" };
	void (Harl::*ptr)(void) = &Harl::debug;
	
	if (level == "debug")
		(this->*ptr)();
	
	/*for (int i = 0; i < 4; i++)
    {
        if (level == lvl_arr[i])
        {
            (this->*funcs[i])();
        }
    }*/


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
	std::cout << "WARNING: Connection to DB failed. Trying second attempt." << std::endl;

}

void Harl::error( void )
{
	std::cout << "ERROR: Unable to connect to DB." << std::endl;

}
