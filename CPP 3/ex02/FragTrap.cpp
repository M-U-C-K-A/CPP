/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:54:33 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 21:19:07 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << INFO << "FragTrap " << this->_name << " created" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << INFO << "FragTrap " << this->_name << " created" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << INFO << "FragTrap " << fragTrap._name << " copied" << RESET << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << INFO << "FragTrap " << this->_name << " destroyed" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout << INFO << "FragTrap assignment called" << RESET << std::endl;
	this->_name = fragTrap._name;
	this->_hitPoints = fragTrap._hitPoints;
	this->_energyPoints = fragTrap._energyPoints;
	this->_attackDamage = fragTrap._attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	if (this->_energyPoints <= 0)
	{
		std::cout << ENERGY << "FragTrap " << this->_name << " has no energy" << RESET << std::endl;
		return;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << DEBUG << "FragTrap " << this->_name << " is dead" << RESET << std::endl;
		return;
	}
	std::cout << HEALTH << "FragTrap " << this->_name << " requests high five" << RESET << std::endl;
	this->_energyPoints--;
}
