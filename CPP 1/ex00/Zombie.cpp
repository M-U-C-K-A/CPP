/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:45:20 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/27 21:59:54 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string s) : _name(s)
{
	std::cout << "\033[0m\033[92m" << _name <<  "→\033[2m   has been created.\033[0m" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "\033[1m\033[91m" << _name << "→\033[2m   has been destroyed.\033[0m" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "\033[1m\033[96m" << _name << "→\033[2m   BraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}
