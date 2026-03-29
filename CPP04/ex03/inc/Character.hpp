/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:08:28 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 18:37:06 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

struct	MateriaGarbageCollector {
	AMateria 					*current;
	MateriaGarbageCollector 	*next;
};


class Character: public ICharacter
{
	private:
		AMateria *_inventory[4];
		MateriaGarbageCollector* _head;
		MateriaGarbageCollector* _tail;
		std::string	_name;
		
		void	_addMateriaToGC(AMateria* m);
		void	_emptyGC();
	
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character& orig);
		Character& operator=(const Character& orig);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* getAMateria(int slot_idx);
};


#endif
