/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:28:36 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/27 19:19:38 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;

	std::string command;
	std::cout << "\033[2J\033[1;1H";
	while (true)
	{
		std::cout << "\033[36m \nEnter command ";
		std::cout << "(\033[32mADD, \033[33mSEARCH, \033[31mEXIT\033[36m): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\n\033[31mEOF detected. Exiting program." << std::endl;
			break ;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
		{
			phoneBook.exitProgram();
			break ;
		}
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
