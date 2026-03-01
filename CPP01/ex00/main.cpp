#include "Zombie.hpp"

int	main( void )
{
	Zombie	zombie_stack("ZombStack");
	zombie_stack.announce();
	
	randomChump("ZombHeap");
}
