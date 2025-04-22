/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:25:08 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/17 21:37:47 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cassert>
#include <vector>
#include <cstdlib>
#include <ctime>

void print_test_header(const std::string& title)
{
	std::cout << BOLD << BLUE << "\n=== " << title << " ===\n" << RESET;
}

void test_basic()
{
	print_test_header("TEST BASIQUE");

	Data original;
	original.value = 42;
	original.name = "Test";

	uintptr_t serialized = Serializer::serialize(&original);
	Data* deserialized = Serializer::deserialize(serialized);

	assert(deserialized == &original);
	assert(deserialized->value == 42);
	assert(deserialized->name == "Test");
	std::cout << GREEN << "✔ Test basique réussi" << RESET << "\n";
}

void test_null_pointer()
{
	print_test_header("TEST POINTEUR NULL");

	Data* null_ptr = NULL;
	uintptr_t serialized = Serializer::serialize(null_ptr);
	Data* deserialized = Serializer::deserialize(serialized);

	assert(deserialized == null_ptr);
	std::cout << GREEN << "✔ Gestion de NULL réussie" << RESET << "\n";
}

void test_multiple_objects()
{
	print_test_header("TEST MULTIPLES OBJETS");

	Data obj1, obj2, obj3;
	obj1.value = 1; obj1.name = "Un";
	obj2.value = 2; obj2.name = "Deux";
	obj3.value = 3; obj3.name = "Trois";

	Data* objects[] = {&obj1, &obj2, &obj3};
	for (size_t i = 0; i < 3; ++i)
	{
		uintptr_t s = Serializer::serialize(objects[i]);
		Data* d = Serializer::deserialize(s);
		assert(d == objects[i]);
	}
	std::cout << GREEN << "✔ Sérialisation multiple réussie" << RESET << "\n";
}

void test_performance()
{
	print_test_header("TEST PERFORMANCE");

	Data data;
	const int iterations = 10000;
	clock_t start = clock();

	for (int i = 0; i < iterations; ++i) {
		uintptr_t s = Serializer::serialize(&data);
		Data* d = Serializer::deserialize(s);
		(void)d;  // Évite l'avertissement unused variable

		// Ajout d'une condition de débogage
		if (i % 100000 == 0)
			std::cout << "Progression: " << i << "/" << iterations << "\r" << std::flush;
	}

	clock_t duration = clock() - start;
	double ms = (double)duration / (CLOCKS_PER_SEC / 1000.0);

	std::cout << MAGENTA << "\n" << iterations << " opérations en " << ms << " ms" << RESET << "\n";
}

int main()
{
	test_performance();
	test_basic();
	test_null_pointer();
	test_multiple_objects();

	std::cout << BOLD << GREEN << "\n🎉 Tous les tests passent avec succès !\n" << RESET;
	return 0;
}
