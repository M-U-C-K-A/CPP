/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:55:13 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 20:11:45 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE << "🧠 Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << BLUE << "🧠 Brain copy constructor called" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "🧠 Brain destructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::copy(other.ideas, other.ideas + 100, this->ideas);
	std::cout << YELLOW << "🧠 Brain assignment operator called" << RESET << std::endl;
	return (*this);
}

std::string const	&Brain::getIdea(int const &index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return (this->ideas[0]);
}

void	Brain::setIdea(int const &index, std::string const &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}
