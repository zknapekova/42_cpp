#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	Brain* _brain;
	
	public:
		Dog( void );
		~Dog( );
		Dog( const Dog& orig);
		Dog& operator=(const Dog& orig);
		
		void makeSound( void ) const;
		const Brain* getBrain(void) const;
};

#endif
