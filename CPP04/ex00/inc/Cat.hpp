#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"


class Cat: public Animal
{
	public:
		Cat( void );
		~Cat( );
		Cat( const Cat& orig);
		Cat& operator=(const Cat& orig);
		
		void makeSound( void ) const;
};

#endif
