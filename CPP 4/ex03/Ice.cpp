/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:09:52 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 21:48:31 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN << "🥶 Ice constructor called" << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << RED << "🥶 Ice destructor called" << RESET << std::endl;
}

AMateria *Ice::clone() const
{
	std::cout << BLUE << "🧬 Cloning Ice materia" << RESET << std::endl;
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << CYAN << "🧊 * shoots an ice bolt at " << BOLD << target.getName()
			<< CYAN << " *" << RESET << std::endl;
}
