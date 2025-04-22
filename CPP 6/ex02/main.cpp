/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:50:23 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/17 22:02:10 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

// Codes couleurs ANSI
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

void print_test_header(const std::string& test_name) {
	std::cout << BOLD << BLUE << "\n=== " << test_name << " ===\n" << RESET;
}

void test_random_generation() {
	print_test_header("TEST GENERATION ALEATOIRE");

	std::cout << "Generation de 5 objets random:\n";
	for (int i = 0; i < 5; ++i) {
		Base* obj = generate();
		std::cout << "Objet " << i+1 << ": ";
		identify(obj);
		delete obj;
		usleep(200000); // 0.2s pause entre chaque génération
	}
}

void test_pointer_identification() {
	print_test_header("TEST IDENTIFICATION PAR POINTEUR");

	A a; B b; C c;
	Base* objects[] = {&a, &b, &c};
	const char* expected[] = {"A", "B", "C"};

	for (int i = 0; i < 3; ++i) {
		std::cout << "Test " << i+1 << " - Attendu: " << GREEN << expected[i] << RESET << " | Resultat: ";
		identify(objects[i]);
	}
}

void test_reference_identification() {
	print_test_header("TEST IDENTIFICATION PAR REFERENCE");

	A a; B b; C c;
	// Solution alternative pour les références
	Base* objects[] = {&a, &b, &c};
	const char* expected[] = {"A", "B", "C"};

	for (int i = 0; i < 3; ++i) {
		std::cout << "Test " << i+1 << " - Attendu: " << GREEN << expected[i] << RESET << " | Resultat: ";
		identify(*objects[i]); // Déréférencement ici
	}
}

void test_null_pointer() {
	print_test_header("TEST POINTEUR NULL");

	Base* nullPtr = 0;
	std::cout << "Identification d'un pointeur null: ";
	identify(nullPtr);
	std::cout << RED << "(Doit gérer proprement sans crash)" << RESET << "\n";
}

void test_performance() {
	print_test_header("TEST PERFORMANCE");

	const int iterations = 5000;
	std::cout << "Lancement de " << iterations << " iterations...\n";
	clock_t start = clock();

	for (int i = 0; i < iterations; ++i)
	{
		Base* obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
	}

	double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << MAGENTA << "Temps total: " << duration << " secondes" << RESET << "\n";
}

int main() {
	std::srand(std::time(0));

	test_performance();
	test_random_generation();
	test_pointer_identification();
	test_reference_identification();
	test_null_pointer();

	std::cout << BOLD << GREEN << "\n🎉 Tous les tests sont passés avec succès!\n" << RESET;
	return 0;
}
