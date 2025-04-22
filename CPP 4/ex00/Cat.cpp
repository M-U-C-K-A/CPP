/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:10:59 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 22:17:20 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << MAGENTA << "🐱 Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << MAGENTA << "🐱 Cat copy constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "🐱 Cat destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << YELLOW << "🐱 Cat assignment operator called" << RESET << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << GREEN << "🐱 Meow!" << RESET << std::endl;
}
