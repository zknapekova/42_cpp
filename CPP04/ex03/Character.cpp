/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:51:16 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/29 19:43:31 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character():_head(NULL), _tail(NULL), _name("None")
{
	for (size_t i = 0; i < 4; i++)
    	_inventory[i] = NULL;
}

Character::Character(std::string name): _head(NULL), _tail(NULL), _name(name)
{
	for (size_t i = 0; i < 4; i++)
    	_inventory[i] = NULL;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
    	if (_inventory[i])
		{
    		delete _inventory[i];
			_inventory[i] = NULL;
		}
    }
	_emptyGC();
}

Character::Character(const Character& orig): _head(NULL), _tail(NULL), _name(orig._name)
{
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
	if (this != &orig)
	{
		_emptyGC();
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
	for (size_t i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m->clone();
			std::cout << "AMateria of type " << m->getType() << " was placed on slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
		{
			_addMateriaToGC(_inventory[idx]);
			_inventory[idx] = NULL;
		}
		else
			std::cout << "Index " << idx << " already unequipped\n";
	}
	else
		std::cerr << "ERROR: (Character::unequip): Wrong index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx < 4) && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cerr << "ERROR: (Character::use): Wrong index" << std::endl;
}

AMateria* Character::getAMateria(int idx)
{
	if ((idx >= 0 && idx < 4) && _inventory[idx])
		return _inventory[idx]->clone();
	return NULL;
}

void	Character::_addMateriaToGC(AMateria* m)
{
	if (!m)
		return ;
	
	MateriaGarbageCollector* new_node = new MateriaGarbageCollector;
	new_node->current = m;
	new_node->next = NULL;
	
	if (_head == NULL)
		_head = new_node;	
	else 
		_tail->next = new_node;
	_tail = new_node;
}

void Character::_emptyGC()
{
    while (_head)
    {
        MateriaGarbageCollector* temp = _head->next;
        delete _head->current;
        delete _head;
        _head = temp;
    }
    _tail = NULL;
}




