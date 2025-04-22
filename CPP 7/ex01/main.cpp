/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:31:02 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/19 19:59:14 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <cmath>
#include <iostream>
#include <string>

// Définition des couleurs ANSI
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

void print_header(const std::string& title)
{
	std::cout << MAGENTA
			<< "\n┌────────────────────────────────────────┐\n"
			<< "│ " << CYAN << title << std::string(39 - title.length(), ' ') << MAGENTA << "│\n"
			<< "└────────────────────────────────────────┘\n" << RESET;
}

// Fonctions de test
template <typename T> void printWithColor(T &element)
{
	std::cout << YELLOW << element << RESET << " ";
}

void	squareNumber(double &num)
{
	num = std::pow(num, 2);
	std::cout << GREEN << "Squared: " << num << RESET << std::endl;
}

void	capitalizeString(std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (i == 0 || str[i - 1] == ' ')
		{
			str[i] = std::toupper(str[i]);
		}
	}
}

struct	Person
{
	std::string name;
	int	age;
};

void	birthday(Person &p)
{
	p.age++;
	std::cout << MAGENTA << "Happy birthday " << p.name << "! Now you're " << p.age << RESET << std::endl;
}

void	printPerson(Person &p)
{
	std::cout << CYAN << p.name << " (" << p.age << " years)" << RESET << std::endl;
}

int	main(void)
{
	int		nums[] = {1, 2, 3, 4, 5};
	double	doubles[] = {1.1, 2.2, 3.3, 4.4};
	Person	people[] = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 20}};
	int		empty[] = {};
	int		*nullArray;

	print_header("TEST 1 - Int array with print");
	iter(nums, 5, printWithColor<int>);
	std::cout << std::endl;
	print_header("TEST 2 - Double array, square function");
	iter(doubles, 4, squareNumber);
	std::cout << "Final values: ";
	iter(doubles, 4, printWithColor<double>);
	std::cout << std::endl;
	print_header("TEST 3 - String array & capitalize");
	std::string words[] = {"hello", "world", "c++ templates"};
	std::cout << "Before: ";
	iter(words, 3, printWithColor<std::string>);
	std::cout << std::endl;
	iter(words, 3, capitalizeString);
	std::cout << "After: ";
	iter(words, 3, printWithColor<std::string>);
	std::cout << std::endl;
	print_header("TEST 4 - Custom object array");
	std::cout << "People:\n";
	iter(people, 3, printPerson);
	iter(people, 3, birthday);
	std::cout << "After birthday:\n";
	iter(people, 3, printPerson);
	print_header("TEST 5 - Edge cases");
	// Test avec tableau vide
	std::cout << "Empty array test: ";
	iter(empty, 0, printWithColor<int>);
	std::cout << "(no output expected)\n";
	// Test avec pointeur null (l'erreur est gérée dans iter)
	nullArray = NULL;
	iter(nullArray, 5, printWithColor<int>);
	std::cout << MAGENTA << "\n━━━━━━━━━━ TESTS TERMINÉS ━━━━━━━━━━\n" << RESET;
	return (0);
}
