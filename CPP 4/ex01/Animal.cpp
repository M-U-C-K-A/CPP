/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:09:39 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 20:47:30 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << BLUE << "·· Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << BLUE << "·· Animal copy constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "·· Animal destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << YELLOW << "·· Animal assignment operator called" << RESET << std::endl;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << GREEN << "·· Generic animal sound!" << RESET << std::endl;
}
