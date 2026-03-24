#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	Brain*	_brain;
	
	public:
		Cat( void );
		~Cat( );
		Cat( const Cat& orig);
		Cat& operator=(const Cat& orig);
		
		void makeSound( void ) const;
		const Brain* getBrain(void) const;
};

#endif
