/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:16 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/28 18:30:37 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character():_name("None")
{
	std::cout << "Character default constructor\n";
	for (size_t i = 0; i < 4; i++)
    	_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character parametrized constructor\n";
	for (size_t i = 0; i < 4; i++)
    	_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor\n";
	for (size_t i = 0; i < 4; i++)
	{
    	if (_inventory[i])
    		delete _inventory[i];
    }
}

Character::Character(const Character& orig): _name(orig._name)
{
	std::cout << "Copy constructor\n";
	for (size_t i = 0; i < 4; i++)
    	_inventory[i] = NULL;
		
	for (size_t i = 0; i < 4; i++)
    {
		if (orig._inventory[i])
			_inventory[i] = orig._inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& orig)
{
	std::cout << "Copy assignment operator\n";
	if (this != &orig)
	{
		this->_name = orig._name;
		for (size_t i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (orig._inventory[i])
				_inventory[i] = orig._inventory[i]->clone();
    	}	
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	std::cout << "Character::equip function called\n";
	
	for (size_t i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "AMateria of type " << m->getType() << " was placed on slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full\n";

}
void Character::unequip(int idx)
{
	//TODO
	(void)idx;

}
void Character::use(int idx, ICharacter& target)
{
	//TODO
	(void)idx;
	(void)target;
}


