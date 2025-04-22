/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:20:51 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 23:32:29 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << GREEN << "📝 Default Form created" << RESET << std::endl;
}

Form::Form(const std::string &name, int gradeToSign,
	int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << GREEN << "📝 Form " << BOLD << _name << GREEN << " created (Sign grade: " << _gradeToSign << ", Exec grade: " << _gradeToExecute << ")" << RESET << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << YELLOW << "📝 Form " << BOLD << _name << YELLOW << " copied" << RESET << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	std::cout << MAGENTA << "📝 Form " << BOLD << _name << MAGENTA << " assigned" << RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "📝 Form " << BOLD << _name << RED << " destroyed" << RESET << std::endl;
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("🚨 Form grade is too high! (must be between 1 and 150)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("🚨 Form grade is too low! (must be between 1 and 150)");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "📝 Form " << BOLD << form.getName() << RESET << " [Status: " << (form.getIsSigned() ? "SIGNED" : "UNSIGNED")
		<< ", Sign grade: " << form.getGradeToSign()
		<< ", Exec grade: " << form.getGradeToExecute() << "]";
	return (os);
}
