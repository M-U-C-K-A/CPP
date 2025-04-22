/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:27:53 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 21:50:34 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	std::cout << GREEN << "📚 MateriaSource constructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
	std::cout << YELLOW << "📚 MateriaSource copy constructor called" << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];
			_templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
		}
		std::cout << MAGENTA << "📚 MateriaSource assignment operator called" << RESET << std::endl;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << RED << "💀 MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m) {
		std::cout << RED << "❌ Error: Cannot learn null materia" << RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			std::cout << BLUE << "📖 Learned " << BOLD << m->getType()
					  << BLUE << " materia" << RESET << std::endl;
			return;
		}
	}
	std::cout << RED << "📚 Cannot learn more materias - template slots full" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
		{
			std::cout << GREEN << "🔮 Creating " << BOLD << type
					  << GREEN << " materia" << RESET << std::endl;
			return _templates[i]->clone();
		}
	}
	std::cout << RED << "❓ Unknown materia type: " << BOLD << type << RESET << std::endl;
	return 0;
}
