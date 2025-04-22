#include <iostream>
#include <cstdlib>
#include "Array.hpp"

// ANSI color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define GRAY "\033[1;37m"
#define RESET "\033[0m"

// Test class
class MyClass {
public:
    int x;
    float y;
    MyClass() : x(0), y(0.0f) {}
    MyClass(int a, float b) : x(a), y(b) {}
};

void print_header(const std::string& title)
{
    std::cout << MAGENTA
            << "\n┌────────────────────────────────────────┐\n"
            << "│ " << CYAN << title << std::string(39 - title.length(), ' ') << MAGENTA << "│\n"
            << "└────────────────────────────────────────┘\n" << RESET;
}

void print_test_case(const std::string& description) {
    std::cout << YELLOW << "• " << description << ":\n" << RESET;
}

void print_success(const std::string& message) {
    std::cout << GREEN << "✓ " << message << RESET << std::endl;
}

void print_error(const std::string& message) {
    std::cout << RED << "✗ " << message << RESET << std::endl;
}

int main() {
    // Test 1: Basic constructions
    {
        print_header("TEST 1 - BASIC CONSTRUCTIONS");

        print_test_case("Empty array");
        Array<int> empty;
        std::cout << "Size: " << empty.size() << std::endl;
        try {
            empty[0] = 42;
            print_error("Should throw an exception");
        } catch (const std::exception& e) {
            print_success(std::string("Exception caught: ") + e.what());
        }

        print_test_case("Array of 5 integers");
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            numbers[i] = i * 10;
        }
        std::cout << "Content: ";
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }

    // Test 2: Copy and assignment
    {
        print_header("TEST 2 - COPY AND ASSIGNMENT");

        print_test_case("Copy constructor");
        Array<std::string> origin(3);
        origin[0] = "Hello";
        origin[1] = "beautiful";
        origin[2] = "world";

        Array<std::string> copy(origin);
        origin[1] = "lovely";

        std::cout << "Original[1]: " << BLUE << origin[1] << RESET << "\n";
        std::cout << "Copy[1]: " << BLUE << copy[1] << RESET << "\n";

        print_test_case("Assignment operator");
        Array<std::string> assigned;
        assigned = origin;
        origin[2] = "!";

        std::cout << "Original[2]: " << BLUE << origin[2] << RESET << "\n";
        std::cout << "Assigned[2]: " << BLUE << assigned[2] << RESET << "\n";
    }

    // Test 3: Boundary checking
    {
        print_header("TEST 3 - BOUNDARY CHECKING");

        Array<char> letters(3);
        letters[0] = 'A';
        letters[1] = 'B';
        letters[2] = 'C';

        print_test_case("Valid access");
        try {
            std::cout << "letters[1] = " << BLUE << letters[1] << RESET << std::endl;
            print_success("Valid access succeeded");
        } catch (...) {
            print_error("Unexpected error");
        }

        print_test_case("Out-of-bounds access");
        try {
            std::cout << "letters[3] = " << letters[3] << std::endl;
            print_error("Should throw an exception");
        } catch (const std::exception& e) {
            print_success(std::string("Exception caught: ") + e.what());
        }
    }

    // Test 4: Complex types
    {
        print_header("TEST 4 - COMPLEX TYPES");

        print_test_case("Array of custom classes");
        Array<MyClass> objects(2);
        objects[0] = MyClass(42, 3.14f);
        objects[1] = MyClass(84, 6.28f);

        for (unsigned int i = 0; i < objects.size(); ++i) {
            std::cout << "Object " << i << ": x=" << objects[i].x
                      << ", y=" << objects[i].y << std::endl;
        }

        print_test_case("Array of arrays");
        Array< Array<int> > matrix(2);
        matrix[0] = Array<int>(3);
        matrix[1] = Array<int>(3);

        for (unsigned int i = 0; i < matrix.size(); ++i) {
            for (unsigned int j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] = i * 10 + j;
            }
        }

        std::cout << "Matrix:\n";
        for (unsigned int i = 0; i < matrix.size(); ++i) {
            for (unsigned int j = 0; j < matrix[i].size(); ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Test 5: Performance and edge cases
    {
        print_header("TEST 5 - EDGE CASES");

        print_test_case("Large array");
        Array<double> bigArray(1000000);
        print_success("Array of 1,000,000 elements created");

        print_test_case("Self-assignment");
        Array<int> selfAssign(5);
        selfAssign = selfAssign;
        print_success("Self-assignment handled correctly");
    }

    std::cout << MAGENTA << "\n━━━━━━━━━━ TESTS COMPLETED ━━━━━━━━━━\n" << RESET;
    return 0;
}

