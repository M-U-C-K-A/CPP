/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:41:07 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/12 21:46:44 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
	typedef AForm *(Intern::*FormCreator)(const std::string &);

	struct					FormType
	{
		std::string name;
		FormCreator			creator;
	};

	static const FormType	formCreators[3];

	AForm *createShrubbery(const std::string &target);
	AForm *createRobotomy(const std::string &target);
	AForm *createPresidential(const std::string &target);

  public:
	Intern();
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target);
};
