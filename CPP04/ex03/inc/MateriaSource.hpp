/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:11:28 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:45:00 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	AMateria *_sources[4];
	
	public:	
		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource& orig);
		MateriaSource& operator=(const MateriaSource& orig);
	
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
		AMateria* getAMateria(int idx);
};

#endif
