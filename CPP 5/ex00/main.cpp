/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:27:01 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 23:16:11 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	// Section 1: Tests de construction de base
	std::cout << BOLD << MAGENTA << "\n====== 🏢 BUREAUCRAT CREATION TESTS 🏢 ======" << RESET << std::endl;
	// Test 1.1: Construction valide
	try
	{
		Bureaucrat normal("Normal Employee", 42);
		std::cout << "✅ " << normal << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "❌ Unexpected error: " << e.what() << RESET << std::endl;
	}
	// Test 1.2: Grade maximum
	try
	{
		Bureaucrat highRank("CEO", 1);
		std::cout << "🏆 " << highRank << " (MAX GRADE)" << std::endl;
		highRank.decrementGrade();
		std::cout << highRank << " (after demotion)" << std::endl;
		highRank.incrementGrade();
		std::cout << highRank << " (after promotion)" << std::endl;
		// Devrait lancer une exception
		highRank.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << RED << "❌ Exception: " << e.what() << RESET << std::endl;
	}
	// Section 2: Tests de grades invalides
	std::cout << BOLD << MAGENTA << "\n====== 🚨 INVALID GRADE TESTS 🚨 ======" << RESET << std::endl;
	// Test 2.1: Grade trop haut
	try
	{
		Bureaucrat tooHigh("Ghost", 0);
		std::cout << RED << "❌ Test failed - no exception thrown" << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "✅ Caught GradeTooHigh: " << e.what() << std::endl;
	}
	// Test 2.2: Grade trop bas
	try
	{
		Bureaucrat tooLow("Peon", 151);
		std::cout << RED << "❌ Test failed - no exception thrown" << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "✅ Caught GradeTooLow: " << e.what() << std::endl;
	}
	// Section 3: Tests de promotions/démissions
	std::cout << BOLD << MAGENTA << "\n====== 📈 PROMOTION/DEMOTION TESTS 📉 ======" << RESET << std::endl;
	// Test 3.1: Montée en grade progressive
	try
	{
		Bureaucrat middle("Department Head", 75);
		std::cout << "Initial: " << middle << std::endl;
		for (int i = 0; i < 5; i++)
		{
			middle.incrementGrade();
			std::cout << middle << " (promotion " << i + 1 << ")" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "❌ Error: " << e.what() << RESET << std::endl;
	}
	// Test 3.2: Descente en grade progressive
	try
	{
		Bureaucrat manager("Team Manager", 25);
		std::cout << "\nInitial: " << manager << std::endl;
		for (int i = 0; i < 10; i++)
		{
			manager.decrementGrade();
			std::cout << manager << " (demotion " << i + 1 << ")" << std::endl;
		}
		// Devrait lancer une exception
		manager.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << RED << "\n❌ Exception: " << e.what() << RESET << std::endl;
	}
	// Section 4: Tests avancés
	std::cout << BOLD << MAGENTA << "\n====== 🧪 ADVANCED TESTS 🧪 ======" << RESET << std::endl;
	// Test 4.1: Copie d'un bureaucrate
	try
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << "\nCopy: " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "❌ Error: " << e.what() << RESET << std::endl;
	}
	// Test 4.2: Auto-assignation
	try
	{
		Bureaucrat selfAssign("Self", 10);
		selfAssign = selfAssign;
		std::cout << "\nAfter self-assignment: " << selfAssign << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "❌ Error: " << e.what() << RESET << std::endl;
	}
	// Test 4.3: Chaînage des méthodes
	try
	{
		Bureaucrat chain("Chain Tester", 10);
		std::cout << "\nBefore chain: " << chain << std::endl;
		chain.incrementGrade();
		chain.decrementGrade();
		chain.incrementGrade();
		std::cout << "After chain: " << chain << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "❌ Error: " << e.what() << RESET << std::endl;
	}
	std::cout << BOLD << GREEN << "\n🏁 ALL TESTS COMPLETED SUCCESSFULLY! 🏁" << RESET << std::endl;
	return (0);
}
