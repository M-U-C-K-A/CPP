/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:39:24 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/03 21:40:25 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
