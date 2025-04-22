/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:50 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 21:56:13 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "💊 Cure constructor called" << RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << RED << "💊 Cure destructor called" << RESET << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << BLUE << "🧬 Cloning Cure materia" << RESET << std::endl;
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << GREEN << "🫀  * heals " << BOLD << target.getName()
			<< GREEN << "'s wounds *" << RESET << std::endl;
}
