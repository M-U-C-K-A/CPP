/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:47:15 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 23:29:41 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << BLUE << "👨‍ Default Bureaucrat created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << BLUE << "👨‍ Bureaucrat " << BOLD << _name << BLUE << " created with grade " << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name),
	_grade(other._grade)
{
	std::cout << YELLOW << "👨‍ Bureaucrat " << BOLD << _name << YELLOW << " copied" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	std::cout << MAGENTA << "👨‍ Bureaucrat " << BOLD << _name << MAGENTA << " assigned" << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "👨‍ Bureaucrat " << BOLD << _name << RED << " destroyed" << RESET << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << GREEN << "😀  " << _name << " promoted to grade " << _grade << RESET << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << YELLOW << "😟  " << _name << " demoted to grade " << _grade << RESET << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("🚨 Grade is too high! (must be between 1 and 150)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("🚨 Grade is too low! (must be between 1 and 150)");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "👨‍ " << BOLD << bureaucrat.getName() << RESET << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << GREEN << "✅ " << _name << " signed " << form.getName() << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "❌ " << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << RESET << std::endl;
    }
}
