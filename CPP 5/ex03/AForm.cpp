/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:04:29 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/11 20:18:09 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150),
    _gradeToExecute(150)
{
    std::cout << GREEN << "📝 Default AForm created" << RESET << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign,
    int gradeToExecute) : _name(name), _isSigned(false),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "📝 AForm " << BOLD << _name << GREEN << " created (Sign grade: " << _gradeToSign << ", Exec grade: " << _gradeToExecute << ")" << RESET << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << YELLOW << "📝 AForm " << BOLD << _name << YELLOW << " copied" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    std::cout << MAGENTA << "📝 AForm " << BOLD << _name << MAGENTA << " assigned" << RESET << std::endl;
    return (*this);
}

AForm::~AForm()
{
    std::cout << RED << "📝 AForm " << BOLD << _name << RED << " destroyed" << RESET << std::endl;
}

const std::string &AForm::getName() const
{
    return (_name);
}

bool AForm::getIsSigned() const
{
    return (_isSigned);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("🚨 AForm grade is too high! (must be between 1 and 150)");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("🚨 AForm grade is too low! (must be between 1 and 150)");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "📝 AForm " << BOLD << form.getName() << RESET << " [Status: " << (form.getIsSigned() ? "SIGNED" : "UNSIGNED")
        << ", Sign grade: " << form.getGradeToSign()
        << ", Exec grade: " << form.getGradeToExecute() << "]";
    return (os);
}
