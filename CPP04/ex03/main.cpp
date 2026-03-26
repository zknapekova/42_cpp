#include "Cure.hpp"
#include "Ice.hpp"


int	main( void )
{
	Ice *ice_ex = new Ice();
	Cure *cure_ex = new Cure();
	
	std::cout << ice_ex->getType() << std::endl;
	std::cout << cure_ex->getType() << std::endl;
	
	Cure *cure_clone = cure_ex->clone();
	Ice *ice_clone = ice_ex->clone();
	
	std::cout << cure_clone->getType() << std::endl;
	std::cout << ice_clone->getType() << std::endl;


	return 0;
}
