/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:08:37 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/05 17:46:54 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Pikachu"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << INFO << "🆕 A wild " << this->_name << " appears! 🐣" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << INFO << "🆕 " << this->_name << " joins the battle! 🎮" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "✨ " << clapTrap._name << " has been cloned! 🐑" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "💀 " << DAMMAGE << this->_name << " has dead! 🪦" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "😴 " << ENERGY << this->_name << " is out of energy! It can't attack! ⚡❌" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "💀 " << BOLD << this->_name << " is knocked out! It can't fight anymore! 🪦" << std::endl;
		return ;
	}
	std::cout << "🔥 " << BOLD << this->_name << " uses TACKLE on " << target << "! It deals " << this->_attackDamage << " damage! 🗡" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "😴 " << this->_name << " is too exhausted to react! ❌" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "💀 " << this->_name << " are already dead! 🪦" << std::endl;
		return ;
	}
	std::cout << "🩸 " << DAMMAGE << this->_name << " takes " << amount << " damage! Ouch! 💥" << std::endl;
	this->_hitPoints -= (int)amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "😴 " << ENERGY << this->_name << " is out of energy! It can't heal! ⚡❌" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "💀 " << DAMMAGE << this->_name << " can't be revived like this! ⚰️" << std::endl;
		return ;
	}
	std::cout << "🧪 " << HEALTH << this->_name << " uses a Potion! It restores " << amount << " HP! 🏥✨" << std::endl;
	this->_hitPoints += (int)amount;
	this->_energyPoints--;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}
