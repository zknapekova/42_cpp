#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
		
	public:
		AAnimal( void );
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal& orig);
		AAnimal& operator=(const AAnimal& orig);
		
		virtual void	makeSound() const = 0;
		std::string		getType( void ) const;
};


#endif
