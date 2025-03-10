/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:27:28 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/10 15:30:44 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::setContactInfo()
{
	std::cout << "\n\033[32mEnter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	std::cout << "\n";
}

bool Contact::isValid() const
{
	return !firstName.empty() && !lastName.empty() && !nickname.empty() && !phoneNumber.empty() && !darkestSecret.empty();
}

void Contact::displayContact() const
{
	std::cout << "\033[0m\033[1mFirst Name: \033[0m" << firstName << std::endl;
	std::cout << "\033[1mLast Name: \033[0m" << lastName << std::endl;
	std::cout << "\033[1mNickname: \033[0m" << nickname << std::endl;
	std::cout << "\033[1mPhone Number: \033[0m" << phoneNumber << std::endl;
	std::cout << "\033[1mDarkest Secret: \033[0m" << darkestSecret << std::endl;
}

void Contact::displayShortInfo(int index) const
{
	std::cout << "│" << std::setw(10) << index
			  << "│" << std::setw(10) << (firstName.size() > 10 ? firstName.substr(0, 9) + "." : firstName)
			  << "│" << std::setw(10) << (lastName.size() > 10 ? lastName.substr(0, 9) + "." : lastName)
			  << "│" << std::setw(10) << (nickname.size() > 10 ? nickname.substr(0, 9) + "." : nickname)
			  << "│" << std::endl;
}
