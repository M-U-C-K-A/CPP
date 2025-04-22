/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:08:37 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 21:18:17 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Pikachu"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << INFO << "ClapTrap " << this->_name << " created" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << INFO << "ClapTrap " << this->_name << " created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << INFO << "ClapTrap " << clapTrap._name << " copied" << RESET << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << INFO << "ClapTrap " << this->_name << " destroyed" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << ENERGY << "ClapTrap " << this->_name << " has no energy left" << RESET << std::endl;
		return;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << DEBUG << "ClapTrap " << this->_name << " is dead" << RESET << std::endl;
		return;
	}
	std::cout << BOLD << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " damage" << RESET << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << DEBUG << "ClapTrap " << this->_name << " is already dead" << RESET << std::endl;
		return;
	}
	std::cout << DAMAGE << "ClapTrap " << this->_name << " takes "
			  << amount << " damage" << RESET << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << ENERGY << "ClapTrap " << this->_name << " has no energy left" << RESET << std::endl;
		return;
	}
	std::cout << HEALTH << "ClapTrap " << this->_name << " repairs "
			  << amount << " hit points" << RESET << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	return (*this);
}
