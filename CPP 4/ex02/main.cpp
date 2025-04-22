/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:27:01 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 20:54:56 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
	// Test 1: Construction/Destruction de base
	std::cout << BLUE << "\n---- BASIC TESTS ----" << RESET << std::endl;
	{
		std::cout << DIM << "[Constructor/Destructor Test]" << RESET << std::endl;
		// CETTE COMMANDE N'EST PLUS VALABLE,
		// on a un constructeur par defaut
		// const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << DIM << "\n[Type Test]" << RESET << std::endl;
		std::cout << "Dog type: " << j->getType() << std::endl;
		std::cout << "Cat type: " << i->getType() << std::endl;

		std::cout << DIM << "\n[Sound Test]" << RESET << std::endl;
		// meta->makeSound();
		j->makeSound();
		i->makeSound();

		std::cout << DIM << "\n[Destructor Test]" << RESET << std::endl;
		// delete meta;
		delete j;
		delete i;
	}

	// Test 2: Copies profondes
		std::cout << MAGENTA << "\n---- DEEP COPY TESTS ----" << RESET << std::endl;
	{
		std::cout << DIM << "[Dog Deep Copy Test]" << RESET << std::endl;
		Dog originalDog;
		originalDog.getBrain()->setIdea(0, "I want a bone");
		Dog copiedDog(originalDog);

		std::cout << "Original Dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
		originalDog.getBrain()->setIdea(0, "I changed my mind");
		std::cout << "After modification:" << std::endl;
		std::cout << "Original Dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

		std::cout << DIM << "\n[Cat Deep Copy Test]" << RESET << std::endl;
		Cat originalCat;
		originalCat.getBrain()->setIdea(0, "I want fish");
		Cat copiedCat(originalCat);

		std::cout << "Original Cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Cat idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
		originalCat.getBrain()->setIdea(0, "Maybe I'll nap instead");
		std::cout << "After modification:" << std::endl;
		std::cout << "Original Cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Cat idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
	}

	// Test 3: Assignation profonde
	std::cout << CYAN << "\n---- DEEP ASSIGNMENT TESTS ----" << RESET << std::endl;
	{
		std::cout << DIM << "[Dog Deep Assignment Test]" << RESET << std::endl;
		Dog dog1;
		dog1.getBrain()->setIdea(0, "I'm the first dog");
		Dog dog2;
		dog2 = dog1;

		std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		dog1.getBrain()->setIdea(0, "I changed my idea");
		std::cout << "After modification:" << std::endl;
		std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << DIM << "\n[Cat Deep Assignment Test]" << RESET << std::endl;
		Cat cat1;
		cat1.getBrain()->setIdea(0, "I'm the first cat");
		Cat cat2;
		cat2 = cat1;

		std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
		cat1.getBrain()->setIdea(0, "Purrrr");
		std::cout << "After modification:" << std::endl;
		std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
	}

	// Test 4: Tableau d'animaux avec Brain
std::cout << BLUE << "\n---- ANIMAL THOUGHTS TEST ----" << RESET << std::endl;
{
	const int zooSize = 4;
	Animal* zoo[zooSize];

	std::cout << DIM << "\n[Opening the zoo]" << RESET << std::endl;
	for (int i = 0; i < zooSize; i++) {
		if (i % 2 == 0) {
			zoo[i] = new Dog();
			// Les chiens pensent à des choses de chiens
			dynamic_cast<Dog*>(zoo[i])->getBrain()->setIdea(0, "I love my bone");
			dynamic_cast<Dog*>(zoo[i])->getBrain()->setIdea(1, "Where's my ball?");
			dynamic_cast<Dog*>(zoo[i])->getBrain()->setIdea(2, "Who's a good boy?");
		} else {
			zoo[i] = new Cat();
			// Les chats pensent à des choses de chats
			dynamic_cast<Cat*>(zoo[i])->getBrain()->setIdea(0, "I need a nap");
			dynamic_cast<Cat*>(zoo[i])->getBrain()->setIdea(1, "This human is my servant");
			dynamic_cast<Cat*>(zoo[i])->getBrain()->setIdea(2, "I'll knock this cup off the table later");
		}
	}

	std::cout << DIM << "\n[Morning in the zoo]" << RESET << std::endl;
	for (int i = 0; i < zooSize; i++) {
		std::cout << zoo[i]->getType() << " says: ";
		zoo[i]->makeSound();

		if (i % 2 == 0) {
			Dog* dog = dynamic_cast<Dog*>(zoo[i]);
			std::cout << "  - Thought 1: " << dog->getBrain()->getIdea(0) << std::endl;
			std::cout << "  - Thought 2: " << dog->getBrain()->getIdea(1) << std::endl;
		} else {
			Cat* cat = dynamic_cast<Cat*>(zoo[i]);
			std::cout << "  - Thought 1: " << cat->getBrain()->getIdea(0) << std::endl;
			std::cout << "  - Thought 2: " << cat->getBrain()->getIdea(1) << std::endl;
		}
	}

	std::cout << DIM << "\n[Closing the zoo]" << RESET << std::endl;
	for (int i = 0; i < zooSize; i++) {
		delete zoo[i];
	}
}

	// Test 5: Vérification des fuites mémoire
	std::cout << MAGENTA << "\n---- MEMORY LEAK TEST ----" << RESET << std::endl;
	{
		// Pour tester avec valgrind, décommenter ces lignes
		std::cout << "Creating animals without deleting them..." << std::endl;
		Animal* leakyDog = new Dog();
		Animal* leakyCat = new Cat();
		delete leakyDog; // Oubli de delete leakyCat
		delete leakyCat;
	}

	return 0;
}
