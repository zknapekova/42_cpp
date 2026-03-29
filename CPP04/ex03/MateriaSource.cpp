#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor\n";
	for (size_t i = 0; i < 4; i++)
    	_sources[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor\n";
	for (size_t i = 0; i < 4; i++)
	{
    	if (_sources[i])
    		delete _sources[i];
    }
}

MateriaSource::MateriaSource( const MateriaSource& orig)
{
	std::cout << "Materia copy constructor\n";
	for (size_t i = 0; i < 4; i++)
    	_sources[i] = NULL;
		
	for (size_t i = 0; i < 4; i++)
    {
		if (orig._sources[i])
			_sources[i] = orig._sources[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& orig)
{
	std::cout << "Materia copy assignment operator\n";
	if (this != &orig)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (_sources[i])
			{
				delete _sources[i];
				_sources[i] = NULL;
			}
			if (orig._sources[i])
				_sources[i] = orig._sources[i]->clone();
    	}	
	}
	return *this;
}


void MateriaSource::learnMateria(AMateria* m)
{
	std::cout << "Materia learnMateria function\n";
	for (size_t i = 0; i < 4; i++)
	{
		if (_sources[i] == NULL)
		{
			_sources[i] = m;
			std::cout << "AMateria was placed on slot " << i << "in MateriaSource\n";
			return ;
		}
	}
	std::cout << "MateriaSource  is full\n";
}
/*
AMateria* MateriaSource::createMateria(std::string const & type)
{


}*/



