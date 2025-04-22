/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:12:30 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 21:21:11 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << INFO << "ScavTrap " << this->_name << " created" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << INFO << "ScavTrap " << this->_name << " created" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << INFO << "ScavTrap " << this->_name << " destroyed" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << INFO << "ScavTrap " << this->_name << " copied" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (this != &scavTrap)
		ClapTrap::operator=(scavTrap);
	std::cout << INFO << "ScavTrap assignment called" << RESET << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	ClapTrap::attack(target);
}

void ScavTrap::guardGate()
{
	std::cout << DEBUG << "ScavTrap " << this->_name << " entered guard mode" << RESET << std::endl;
}
