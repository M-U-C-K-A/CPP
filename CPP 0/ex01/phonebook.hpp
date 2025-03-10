/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:27:02 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/10 17:47:12 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class Contact
{
  private:
	std::string firstName;		// Le prénom du contact
	std::string lastName;		// Le nom du contact
	std::string nickname;		// Le surnom du contact
	std::string phoneNumber;	// Le numéro de telephone
	std::string darkestSecret;	// Le secret le plus noir
  public:
	void setContactInfo();
	bool isValid() const;
	void displayContact() const;
	void displayShortInfo(int index) const;
};

class PhoneBook
{
  private:
	Contact contacts[8];	// Le tableau de contacts
	int currentIndex;		// L'indice actuel pour ajouter un nouveau contact
	int contactCount;		// Nombre de contacts ajoutés

  public:
	PhoneBook();			// Constructeur par défaut
	void addContact();		// Ajoute un nouveau contact
	void searchContacts() const;	// Cherche et affiche les contacts
	void displayContacts() const;	// Affiche tous les contacts
	void exitProgram() const;		// Quitte le programme
};
