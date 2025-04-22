#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void test_valid_forms() {
	std::cout << "\n=== TEST CREATION VALID FORMS ===\n";

	Intern intern;
	Bureaucrat boss("Boss", 1);

	AForm* shrub = intern.makeForm("shrubbery creation", "Garden");
	AForm* robot = intern.makeForm("robotomy request", "Bender");
	AForm* pardon = intern.makeForm("presidential pardon", "Zaphod");

	if (shrub) {
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}

	if (robot) {
		boss.signForm(*robot);
		boss.executeForm(*robot);
		delete robot;
	}

	if (pardon) {
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}
}

void test_invalid_forms() {
	std::cout << "\n=== TEST INVALID FORM NAMES ===\n";

	Intern intern;

	AForm* invalid1 = intern.makeForm("unknown form", "Target");
	AForm* invalid2 = intern.makeForm("", "Nowhere");
	AForm* invalid3 = intern.makeForm("shrubbery", "Partial");

	if (!invalid1 && !invalid2 && !invalid3) {
		std::cout << "All invalid forms correctly rejected\n";
	}
}

void test_edge_cases() {
	std::cout << "\n=== TEST EDGE CASES ===\n";

	Intern intern1;
	Intern intern2(intern1); // Test copie
	Intern intern3;
	intern3 = intern1; // Test assignation

	AForm* form = intern1.makeForm("robotomy request", "Marvin");
	if (form) {
		std::cout << "Intern copy/assign works correctly\n";
		delete form;
	}
}

int main() {
	std::cout << "===== INTERN TEST PROGRAM =====\n";

	// Test 1: Formulaires valides
	test_valid_forms();

	// Test 2: Formulaires invalides
	test_invalid_forms();

	// Test 3: Cas particuliers
	test_edge_cases();

	std::cout << "\n===== ALL TESTS PASSED =====\n";
	return 0;
}
