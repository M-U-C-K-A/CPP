#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
protected:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    virtual ~AForm();

    AForm& operator=(const AForm& other);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0; // Méthode abstraite

    class GradeTooHighException : public std::exception {
        public: virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public: virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
