/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:42:23 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/17 20:42:58 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <iostream>
#include <math.h>

// Définition des codes ANSI pour les couleurs et styles
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void ScalarConverter::convert(const std::string &literal)
{
	char	c;
	char	*endPtr;
	double	d;
	float	f;

	// Check for empty string
	if (literal.empty())
	{
		std::cerr << RED << BOLD << "Error: empty string" << RESET << std::endl;
		return ;
	}
	// Check for special cases (nan, inf, etc.)
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << BOLD << GREEN << "char: " << RESET << "impossible" << std::endl;
		std::cout << BOLD << GREEN << "int: " << RESET << "impossible" << std::endl;
		std::cout << BOLD << GREEN << "float: " << RESET << "nanf" << std::endl;
		std::cout << BOLD << GREEN << "double: " << RESET << "nan" << std::endl;
		return ;
	}
	if (literal == "+inf" || literal == "+inff" || literal == "inf"
		|| literal == "inff")
	{
		std::cout << BOLD << GREEN << "char: " << RESET << "impossible" << std::endl;
		std::cout << BOLD << GREEN << "int: " << RESET << "impossible" << std::endl;
		std::cout << BOLD << GREEN << "float: " << RESET << "+inff" << std::endl;
		std::cout << BOLD << GREEN << "double: " << RESET << "+inf" << std::endl;
		return ;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << BOLD << GREEN << "char: " << RESET << "impossible" << std::endl;
		std::cout << BOLD << GREEN << "int: " << RESET << "impossible" << std::endl;
		std::cout << BOLD << GREEN << "float: " << RESET << "-inff" << std::endl;
		std::cout << BOLD << GREEN << "double: " << RESET << "-inf" << std::endl;
		return ;
	}
	// Check for char literal
	if (literal.length() == 1 && !isdigit(literal[0]))
	{
		c = literal[0];
		std::cout << BOLD << GREEN << "char: " << RESET << "'" << BOLD << CYAN << c << RESET << "'" << std::endl;
		std::cout << BOLD << GREEN << "int: " << RESET << BOLD << YELLOW << static_cast<int>(c) << RESET << std::endl;
		std::cout << BOLD << GREEN << "float: " << RESET << BOLD << MAGENTA << static_cast<float>(c) << ".0f" << RESET << std::endl;
		std::cout << BOLD << GREEN << "double: " << RESET << BOLD << BLUE << static_cast<double>(c) << ".0" << RESET << std::endl;
		return ;
	}
	// Try to parse as int, float, or double
	d = strtod(literal.c_str(), &endPtr);
	// Check if the entire string was consumed
	if (*endPtr == '\0' || (*endPtr == 'f' && *(endPtr + 1) == '\0'))
	{
		// Char conversion
		std::cout << BOLD << GREEN << "char: " << RESET;
		if (d < CHAR_MIN || d > CHAR_MAX || isnan(d))
			std::cout << "impossible" << std::endl;
		else if (!isprint(static_cast<char>(d)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << BOLD << CYAN << static_cast<char>(d) << RESET << "'" << std::endl;

		// Int conversion
		std::cout << BOLD << GREEN << "int: " << RESET;
		if (d < INT_MIN || d > INT_MAX || isnan(d))
			std::cout << "impossible" << std::endl;
		else
			std::cout << BOLD << YELLOW << static_cast<int>(d) << RESET << std::endl;

		// Float conversion
		f = static_cast<float>(d);
		std::cout << BOLD << GREEN << "float: " << RESET << BOLD << MAGENTA << f;
		if (f == floor(f) && f >= -1000000 && f <= 1000000)
			std::cout << ".0";
		std::cout << "f" << RESET << std::endl;

		// Double conversion
		std::cout << BOLD << GREEN << "double: " << RESET << BOLD << BLUE << d;
		if (d == floor(d) && d >= -1000000 && d <= 1000000)
			std::cout << ".0";
		std::cout << RESET << std::endl;
	}
	else
		std::cerr << RED << BOLD << "Error: invalid literal format" << RESET << std::endl;
}
