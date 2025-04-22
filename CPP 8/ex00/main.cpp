#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <sstream>
#include "easyfind.hpp"

// ANSI color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define GRAY "\033[1;37m"
#define RESET "\033[0m"

void print_header(const std::string& title)
{
	std::cout << MAGENTA
			  << "\n┌────────────────────────────────────────┐\n"
			  << "│ " << CYAN << title << std::string(39 - title.length(), ' ') << MAGENTA << "│\n"
			  << "└────────────────────────────────────────┘\n" << RESET;
}

template <typename Container>
void test_easyfind(Container& c, const std::string& type_name, int value)
{
	std::cout << YELLOW << "\nTesting " << type_name << " with value " << value << RESET << std::endl;
	std::cout << GRAY << "Container content: [";
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it;
		if (it != --c.end()) std::cout << ", ";
	}
	std::cout << "]" << RESET << std::endl;

	try {
		typename Container::iterator it = easyfind(c, value);
		std::cout << GREEN << "✓ Found value " << *it
				 << " at position " << std::distance(c.begin(), it) << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "✗ " << e.what() << RESET << std::endl;
	}
}

int main()
{
	// Test data
	const int test_values[] = {5, 10, 15, 20, 25, 30};
	const int test_cases[] = {15, 35, 5, 25, -3};
	const size_t values_size = sizeof(test_values)/sizeof(test_values[0]);

	// Initialize containers once
	std::vector<int> vec(test_values, test_values + values_size);
	std::list<int> lst(test_values, test_values + values_size);
	std::deque<int> deq(test_values, test_values + values_size);
	std::set<int> s(test_values, test_values + values_size);

	// Special cases
	std::vector<int> empty_vec;
	std::vector<int> dup_vec;
	int dup_values[] = {1, 2, 2, 2, 3};
	dup_vec.insert(dup_vec.end(), dup_values, dup_values + 5);

	std::list<int> neg_list;
	int neg_values[] = {-5, -3, 0, 3, 5};
	neg_list.insert(neg_list.end(), neg_values, neg_values + 5);

	// Main test sequence
	print_header("TEST 1 - BASIC FUNCTIONALITY TESTS");
	for (size_t i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); ++i) {
		int val = test_cases[i];
		test_easyfind(vec, "vector", val);
		test_easyfind(lst, "list", val);
		test_easyfind(deq, "deque", val);
		test_easyfind(s, "set", val);
	}

	// Edge cases
	print_header("TEST 2 - EDGE CASE TESTS");
	test_easyfind(empty_vec, "empty vector", 42);
	test_easyfind(dup_vec, "vector with duplicates", 2);
	test_easyfind(neg_list, "list with negative values", -3);

	std::cout << MAGENTA << "\n━━━━━━━━━━ TESTS COMPLETED ━━━━━━━━━━\n" << RESET;
	return 0;
}
