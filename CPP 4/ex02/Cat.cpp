/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:10:59 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 20:23:22 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << MAGENTA << "🐱 Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << MAGENTA << "🐱 Cat copy constructor called" << RESET << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat::~Cat()
{
	delete brain;
	std::cout << RED << "🐱 Cat destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << YELLOW << "🐱 Cat assignment operator called" << RESET << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << GREEN << "🐱 Meow!" << RESET << std::endl;
}

Brain* Cat::getBrain() const {
	return brain;
}
