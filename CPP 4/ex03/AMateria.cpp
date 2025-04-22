/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:08:45 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 21:40:39 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << GREEN << "✨ AMateria constructor called for type "
			<< BOLD << type << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED << "💥 AMateria destructor called for type "
			<< BOLD << _type << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << CYAN << "* uses materia on " << BOLD << target.getName()
			<< CYAN << " *" << RESET << std::endl;
}
