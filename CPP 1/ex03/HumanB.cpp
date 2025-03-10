/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:00:24 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/03 23:21:10 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :_name(name)
{
	std::cout << "\033[1;92m◎ HumanB (" << this->_name << ") created.\033[0m" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "\033[1;91m◎ HumanB (" << this->_name << ") destroyed.\033[0m" << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << "\033[1;93m◎ " << this->_name << " attacks\033[3;2m with ";
	std::cout << this->_weapon->getType() << ".\033[0m" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

