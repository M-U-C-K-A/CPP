/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:27:46 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/25 20:56:15 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0)
{
}

void PhoneBook::addContact()
{
	if (contactCount < 8)
	{
		contacts[contactCount].setContactInfo();
		contactCount++;
	}
	else
	{
		contacts[currentIndex].setContactInfo();
		currentIndex = (currentIndex + 1) % 8;
	}
}

void PhoneBook::searchContacts() const
{
	displayContacts();
	std::string input;
	int index = -1;

	std::cout << "Enter the index of the contact you want to view: ";
	std::cin >> input;

	if (input.find_first_not_of("0123456789") == std::string::npos)
		index = atoi(input.c_str());
	else
	{
		std::cout << "Invalid input! Please enter a number between 0 and 7." << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return ;
	}
	if (index >= 0 && index < 8 && contacts[index].isValid())
		contacts[index].displayContact();
	else
		std::cout << "Invalid index OR contact!" << std::endl;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

void PhoneBook::displayContacts() const
{
	std::cout << "\033[2J\033[1;1H\033[1;33m\n";
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│   Index  │First Name│ Last Name│ Nickname │" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i < contactCount; i++)
		contacts[i].displayShortInfo(i);
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void PhoneBook::exitProgram() const
{
	std::cout << "\033[31mExiting... Goodbye!" << std::endl;
}
