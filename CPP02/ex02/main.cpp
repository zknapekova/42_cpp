#include "Fixed.hpp"

int main( void ) {

	Fixed const b( 81 + Fixed(30 ));
	std::cout << b << std::endl;
	Fixed const c( 3.3f + Fixed(30 ));
	std::cout << c << std::endl;
	/*std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;*/
	return 0;
}
