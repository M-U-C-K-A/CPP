/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:34:09 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/03 23:20:53 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "\033[1;92m◎ HumanB (" << this->_name << ") created.\033[3;2m width ";
	std::cout << this->_weapon.getType() << ".\033[0m" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "\033[1;91m◎ HumanA (" << this->_name << ") destroyed.\033[0m" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << "\033[1;93m◎ " << this->_name << " attacks.\033[3;2m with ";
	std::cout << this->_weapon.getType() << ".\033[0m" << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}
