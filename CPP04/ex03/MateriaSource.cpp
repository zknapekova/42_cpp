/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:11:06 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 17:17:07 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!m)
	{
		std::cerr << "ERROR: (MateriaSource::learnMateria) invalid input\n";
		return ;
	}
	std::cout << "Materia learnMateria function\n";
	for (size_t i = 0; i < 4; i++)
	{
		if (_sources[i] == NULL)
		{
			_sources[i] = m;
			std::cout << "AMateria with type " <<  _sources[i]->getType() << " was placed on slot " << i << " in MateriaSource\n";
			return ;
		}
	}
	std::cout << "MateriaSource  is full\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_sources[i])
		{
			if (_sources[i]->getType() == type)
				return _sources[i]->clone();
		}	
	}
	std::cerr << "ERROR: (MateriaSource::createMateria): No valid MateriaSource found\n";
	return NULL;
}

AMateria* MateriaSource::getAMateria(int idx)
{
	if (idx >= 0 && idx < 4)
		return _sources[idx]->clone();
	return NULL;
}




