/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:11:29 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 20:23:38 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << CYAN << "🐶 Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << CYAN << "🐶 Dog copy constructor called" << RESET << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog::~Dog()
{
	delete brain;
	std::cout << RED << "🐶 Dog destructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << YELLOW << "🐶 Dog assignment operator called" << RESET << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << GREEN << "🐶 Woof!" << RESET << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
