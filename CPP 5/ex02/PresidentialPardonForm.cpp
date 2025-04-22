/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:31:51 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/11 20:31:51 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("Presidential Pardon", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute()) throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox!\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {}
