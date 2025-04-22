/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:13:49 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 21:51:49 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << GREEN << "🧙 Character constructor called for "
			<< BOLD << name << RESET << std::endl;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	std::cout << YELLOW << "👦 Character copy constructor called for "
			<< BOLD << _name << RESET << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
		}
		std::cout << MAGENTA << "👦 Character assignment operator called for "
				<< BOLD << _name << RESET << std::endl;
	}
	return *this;
}

Character::~Character()
{
	std::cout << RED << "👦 Character destructor called for "
			  << BOLD << _name << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << RED << "❌ Error: Cannot equip null materia" << RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << BLUE << "🎒 Equipped " << BOLD << m->getType()
					  << BLUE << " in slot " << i << RESET << std::endl;
			return;
		}
	}
	std::cout << RED << "🛑 Inventory full! Could not equip "
			  << BOLD << m->getType() << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << YELLOW << "Unequipped " << BOLD << _inventory[idx]->getType()
				  << YELLOW << " from slot " << idx << RESET << std::endl;
		_inventory[idx] = NULL;
	}
	else
		std::cout << RED << "Invalid unequip index: " << idx << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << CYAN << "🔮 " << _name << " uses materia in slot " << idx << ":" << RESET << std::endl;
		_inventory[idx]->use(target);
	}
	else
		std::cout << RED << "❌ Invalid use index: " << idx << RESET << std::endl;
}
