/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:27:01 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 23:22:00 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << BOLD << MAGENTA << "\n====== 🏢 BUREAUCRAT TESTS ======" << RESET << std::endl;

    try {
        Bureaucrat ceo("CEO", 1);
        Bureaucrat intern("Intern", 150);
        std::cout << "✅ " << ceo << "\n✅ " << intern << std::endl;
    } catch (...) {}

    std::cout << BOLD << MAGENTA << "\n====== 📝 FORM TESTS ======" << RESET << std::endl;

    // Test 1: Form creation
    try {
        Form taxForm("Tax Return", 50, 25);
        Form contract("Employment Contract", 10, 5);
        std::cout << "✅ " << taxForm << "\n✅ " << contract << std::endl;

        // Test invalid form
        Form invalid("Invalid", 0, 151);
    } catch (std::exception& e) {
        std::cout << RED << "❌ " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << MAGENTA << "\n====== ✍️ SIGNING TESTS ======" << RESET << std::endl;

    // Test 2: Form signing
    try {
        Bureaucrat director("Director", 10);
        Bureaucrat clerk("Clerk", 70);

        Form important("Important Form", 20, 10);
        Form simple("Simple Form", 50, 50);

        std::cout << "\nBefore signing:\n" << important << "\n" << simple << std::endl;

        // Director can sign both
        director.signForm(important);
        director.signForm(simple);

        // Clerk can only sign simple form
        clerk.signForm(simple);
        clerk.signForm(important);  // Should fail

        std::cout << "\nAfter signing:\n" << important << "\n" << simple << std::endl;
    } catch (...) {}

    std::cout << BOLD << MAGENTA << "\n====== 🧪 ADVANCED TESTS ======" << RESET << std::endl;

    // Test 3: Copy and assignment
    try {
        Form original("Original", 30, 20);
        Form copy(original);
        Form assigned("Temporary", 100, 100);

        assigned = original;
        std::cout << "Original: " << original << "\nCopy: " << copy
                  << "\nAssigned: " << assigned << std::endl;
    } catch (...) {}

    // Test 4: Edge cases
    try {
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);

        Form topForm("Top Secret", 1, 1);
        Form bottomForm("Public", 150, 150);

        top.signForm(topForm);
        bottom.signForm(bottomForm);
        bottom.signForm(topForm);  // Should fail
    } catch (...) {}

    std::cout << BOLD << GREEN << "\n🏁 ALL TESTS COMPLETED! 🏁" << RESET << std::endl;
    return 0;
}
