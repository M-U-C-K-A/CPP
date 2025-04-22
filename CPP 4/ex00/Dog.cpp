/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:11:29 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 22:16:22 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << CYAN << "🐶 Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << CYAN << "🐶 Dog copy constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "🐶 Dog destructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << YELLOW << "🐶 Dog assignment operator called" << RESET << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << GREEN << "🐶 Woof!" << RESET << std::endl;
}
