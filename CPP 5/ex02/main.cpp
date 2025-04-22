/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:42:27 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/12 21:42:27 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void testTitle(const std::string &title)
{
	std::cout << "\n\033[1;34m=== " << title << " ===\033[0m\n";
}

int	main(void)
{
	testTitle("1. Création des bureaucrates");
	Bureaucrat high("High", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 150);
	std::cout << high << "\n" << mid << "\n" << low << std::endl;
	testTitle("2. Création des formulaires");
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Zaphod");
	std::cout << shrub << "\n" << robot << "\n" << pardon << std::endl;
	testTitle("3. Tentative de signature avec grade trop bas");
	try
	{
		low.signForm(shrub);
		low.signForm(robot);
		low.signForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31mError: " << e.what() << "\033[0m" << std::endl;
	}
	testTitle("4. Signature des formulaires");
	high.signForm(shrub);
	mid.signForm(robot);
	high.signForm(pardon);
	std::cout << shrub << "\n" << robot << "\n" << pardon << std::endl;
	testTitle("5. Tentative d'exécution avec grade trop bas");
	try
	{
		low.executeForm(shrub);
		mid.executeForm(robot); // Doit échouer (grade 50 > 45)
		low.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31mError: " << e.what() << "\033[0m" << std::endl;
	}
	testTitle("6. Exécution réussie des formulaires");
	high.executeForm(shrub);  // Crée home_shrubbery
	high.executeForm(robot);  // 50% chance de réussite
	high.executeForm(robot);  // 50% chance de réussite
	high.executeForm(pardon); // Pardon présidentiel
	testTitle("7. Test copie et assignation");
	{
		ShrubberyCreationForm shrubCopy(shrub);
		PresidentialPardonForm pardonAssign("Temp");
		pardonAssign = pardon;
		std::cout << "Copie: " << shrubCopy << "\nAssignation: " << pardonAssign << std::endl;
	}
	testTitle("8. Cas limites et erreurs");
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31mError creating TooHigh: " << e.what() << "\033[0m" << std::endl;
	}
	testTitle("9. Exécution sans signature");
	ShrubberyCreationForm unsignedShrub("garden");
	RobotomyRequestForm unsignedRobot("Bender");
	PresidentialPardonForm unsignedPardon("Zaphod");
	try
	{
		high.executeForm(unsignedPardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31mError executing unsigned form: " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		high.executeForm(unsignedRobot);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31mError executing unsigned form: " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		high.executeForm(unsignedShrub);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31mError executing unsigned form: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "\n\033[1;32m=== TESTS COMPLETS ===\033[0m" << std::endl;

	return (0);
}
