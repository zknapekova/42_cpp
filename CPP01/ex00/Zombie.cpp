#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string _name): name(_name)
{ }


void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << name << ": Zombie destroyed" << std::endl;

}

