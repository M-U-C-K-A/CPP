/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:57:16 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 20:52:19 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define RESET "\033[0m"
#define BOLD "\033[0;1m"
#define DIM "\033[2m"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	std::string getType() const;
	virtual void makeSound() const = 0;
};
