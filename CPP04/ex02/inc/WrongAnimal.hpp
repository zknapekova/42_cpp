#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
		
	public:
		WrongAnimal( void );
		WrongAnimal(std::string type);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& orig);
		WrongAnimal& operator=(const WrongAnimal& orig);
		
		void	makeSound( void ) const;
		std::string		getType( void ) const;
};

#endif
