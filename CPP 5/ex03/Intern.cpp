#include "Intern.hpp"
#include <iostream>

// Messages de log colorés
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

AForm* Intern::createShrubbery(const std::string& target) {
    std::cout << BLUE << "[Intern] Creating ShrubberyCreationForm targeting " << target << RESET << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    std::cout << BLUE << "[Intern] Creating RobotomyRequestForm targeting " << target << RESET << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    std::cout << BLUE << "[Intern] Creating PresidentialPardonForm targeting " << target << RESET << std::endl;
    return new PresidentialPardonForm(target);
}

const Intern::FormType Intern::formCreators[3] = {
    {"shrubbery creation", &Intern::createShrubbery},
    {"robotomy request", &Intern::createRobotomy},
    {"presidential pardon", &Intern::createPresidential}
};

Intern::Intern() {
    std::cout << GREEN << "[Intern] New intern hired" << RESET << std::endl;
}

Intern::~Intern() {
    std::cout << RED << "[Intern] Intern finished their internship" << RESET << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::cout << BLUE << "\n[Intern] Received request to create form: '"
              << formName << "' with target: '" << target << "'" << RESET << std::endl;

    for (int i = 0; i < 3; ++i) {
        if (formName == formCreators[i].name) {
            std::cout << GREEN << "[Intern] Found matching form type: " << formName << RESET << std::endl;
            AForm* form = (this->*formCreators[i].creator)(target);
            std::cout << GREEN << "[Intern] Successfully created form: " << formName << RESET << "\n\n";
            return form;
        }
    }

    std::cerr << RED << "[Intern] Error: Unknown form name '" << formName << "'" << RESET << std::endl;
    std::cerr << RED << "[Intern] Available forms are: \n"
              << "- shrubbery creation\n- robotomy request\n- presidential pardon" << RESET << "\n\n";
    return NULL;
}
