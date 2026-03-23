#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		~Dog( );
		Dog( const Dog& orig);
		Dog& operator=(const Dog& orig);
		
		void makeSound( void ) const;
};

#endif
