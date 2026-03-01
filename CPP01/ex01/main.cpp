#include "Zombie.hpp"

int	main( void )
{
	Zombie *zomb_arr = zombieHorde(5, "Arnold");
	
	for (int i = 0; i < 5; i++)
		zomb_arr->announce();
	delete[] zomb_arr;
}
