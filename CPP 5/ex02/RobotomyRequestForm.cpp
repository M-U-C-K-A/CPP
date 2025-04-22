/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:31:33 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/11 20:31:39 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request", 72, 45), _target(target) {
    std::srand(std::time(0));
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute()) throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *\n";
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!\n";
    } else {
        std::cout << "Robotomy failed for " << _target << "!\n";
    }
}

RobotomyRequestForm::~RobotomyRequestForm() {}
