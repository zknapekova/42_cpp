#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat( void );
		~WrongCat( );
		WrongCat( const WrongCat& orig);
		WrongCat& operator=(const WrongCat& orig);
		
		void makeSound( void ) const;
};

#endif
