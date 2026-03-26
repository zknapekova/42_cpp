#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& orig);
		Cure& operator=(const Cure& orig);
		
		Cure* clone() const;
		//void use(ICharacter& target);
};

#endif
