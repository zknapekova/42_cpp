#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
	AMateria* _sources[4];
	
	public:	
		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource& orig);
		MateriaSource& operator=(const MateriaSource& orig);
	
		void learnMateria(AMateria* m);
		//AMateria* createMateria(std::string const & type);
};

#endif
