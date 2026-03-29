/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:12:18 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 16:12:18 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	
	public:
		AMateria(std::string const &type);
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria& orig);
		AMateria& operator=(const AMateria& orig);
		
		std::string const & getType() const; 
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};


#endif
