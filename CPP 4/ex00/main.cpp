/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:27:01 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 22:47:12 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << RESET << DIM << "---- BASIC TESTS ----" << RESET << std::endl;
	{
		std::cout << "\n" << DIM << "[Constructor/Destructor Test]" << RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\n" << DIM << "[Type Test]" << RESET << std::endl;
		std::cout << "Dog type: " << j->getType() << std::endl;
		std::cout << "Cat type: " << i->getType() << std::endl;

		std::cout << "\n" << DIM << "[Sound Test]" << RESET << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound();

		std::cout << "\n" << DIM << "[Destructor Test]" << RESET << std::endl;
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n" << RESET << DIM << "---- COPY TESTS ----" << RESET << std::endl;
	{
		std::cout << "\n" << DIM << "[Dog Copy Test]" << RESET << std::endl;
		Dog originalDog;
		Dog copiedDog(originalDog);
		std::cout << "Original: "; originalDog.makeSound();
		std::cout << "Copy: "; copiedDog.makeSound();

		std::cout << "\n" << DIM << "[Cat Copy Test]" << RESET << std::endl;
		Cat originalCat;
		Cat copiedCat(originalCat);
		std::cout << "Original: "; originalCat.makeSound();
		std::cout << "Copy: "; copiedCat.makeSound();
	}

	std::cout << "\n" << RESET << DIM << "---- ASSIGNMENT TESTS ----" << RESET << std::endl;
	{
		std::cout << "\n" << DIM << "[Dog Assignment Test]" << RESET << std::endl;
		Dog dog1;
		Dog dog2;
		dog2 = dog1;
		std::cout << "Dog1: "; dog1.makeSound();
		std::cout << "Dog2: "; dog2.makeSound();

		std::cout << "\n" << DIM << "[Cat Assignment Test]" << RESET << std::endl;
		Cat cat1;
		Cat cat2;
		cat2 = cat1;
		std::cout << "Cat1: "; cat1.makeSound();
		std::cout << "Cat2: "; cat2.makeSound();
	}

	std::cout << "\n" << RESET << DIM << "---- ARRAY TEST ----" << RESET << std::endl;
	{
		const int size = 4;
		Animal* animals[size];

		std::cout << "\n" << DIM << "[Creating Animals]" << RESET << std::endl;
		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << "\n" << DIM << "[Making Sounds]" << RESET << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
			animals[i]->makeSound();
		}

		std::cout << "\n" << DIM << "[Deleting Animals]" << RESET << std::endl;
		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	std::cout << "\n" << RESET << DIM << "---- POLYMORPHISM TEST ----" << RESET << std::endl;
	{
		Animal* animals[2];
		animals[0] = new Dog();
		animals[1] = new Cat();

		for (int i = 0; i < 2; i++)
		{
			std::cout << "Animal " << i << " sound: ";
			animals[i]->makeSound();
		}
		for (int i = 0; i < 2; i++)
			delete animals[i];
	}

	return 0;
}
