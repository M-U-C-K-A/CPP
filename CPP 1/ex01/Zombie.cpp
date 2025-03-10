/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:45:20 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/27 23:48:11 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "\033[0m\033[92m\033[2m ○ new zombie has been created.\033[0m" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "\033[0m\033[92m ○ " << _name <<  "\033[2m has been created.\033[0m" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "\033[1m\033[91m ○ " << _name << "\033[2m has been destroyed.\033[0m" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "\033[1m\033[96m ○ " << _name << "\033[2m BraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
