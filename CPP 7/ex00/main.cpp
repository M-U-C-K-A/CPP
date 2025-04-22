/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:28:51 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/19 20:04:18 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream> // Added missing header

// ANSI color codes
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

void print_result(const std::string& name, const std::string& value)
{
	std::cout << YELLOW << std::setw(10) << std::left << name << RESET << ": " << GREEN << value << RESET << "\n";
}

void print_result(const std::string& name, int value)
{
	std::cout << YELLOW << std::setw(10) << std::left << name << RESET << ": " << GREEN << value << RESET << "\n";
}

int main()
{
	print_header("TEST 1 - WITH INTEGERS");
	{
		int a = 2;
		int b = 3;

		print_result("Before swap", "a = 2, b = 3");
		::swap(a, b);

		std::ostringstream oss;
		oss << "a = " << a << ", b = " << b;
		print_result("After swap", oss.str());

		print_result("min(a,b)", ::min(a, b));
		print_result("max(a,b)", ::max(a, b));
	}

	print_header("TEST 2 - WITH STRINGS");
	{
		std::string c = "string1";
		std::string d = "string2";

		print_result("Before swap", "c = string1, d = string2");
		::swap(c, d);

		std::ostringstream oss;
		oss << "c = " << c << ", d = " << d;
		print_result("After swap", oss.str());

		print_result("min(c,d)", ::min(c, d));
		print_result("max(c,d)", ::max(c, d));
	}

	std::cout << MAGENTA << "\n━━━━━━━━━━ TESTS TERMINÉS ━━━━━━━━━━\n" << RESET;
	return 0;
}

