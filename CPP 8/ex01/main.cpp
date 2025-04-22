#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <list>
#include <vector>

// ANSI color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define GRAY "\033[1;37m"
#define RESET "\033[0m"

void	printTestHeader(const std::string &testName)
{
	std::cout << MAGENTA << "\n=== " << testName << " ===\n" << RESET;
}

void	print_header(const std::string &title)
{
	std::cout << MAGENTA << "\n┌────────────────────────────────────────┐\n"
				<< "│ " << CYAN << title << std::string(39 - title.length(),
					' ') << MAGENTA << "│\n"
				<< "└────────────────────────────────────────┘\n"
				<< RESET;
}

void	testBasicOperations(void)
{
	print_header("TEST 1 - BASIC OPERATIONS TEST");
	Span sp(5);
	std::cout << CYAN << "Adding single numbers..." << RESET << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << " (expected: 2)\n";
	std::cout << "Longest span: " << sp.longestSpan() << " (expected: 14)\n";
}

void	testExceptions(void)
{
	print_header("TEST 2 - EXCEPTION HANDLING TEST");
	Span sp(3);
	std::cout << CYAN << "Testing overflow..." << RESET << std::endl;
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4); // Should throw
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
	std::cout << CYAN << "\nTesting empty span..." << RESET << std::endl;
	Span empty(0);
	try
	{
		empty.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
	std::cout << CYAN << "\nTesting single element span..." << RESET << std::endl;
	Span single(1);
	single.addNumber(42);
	try
	{
		single.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Caught exception: " << e.what() << RESET << "\n";
	}
}

void	testRangeInsertion(void)
{
	print_header("TEST 3 - RANGE INSERTION TEST");
	Span sp(10);
	std::cout << CYAN << "Adding range from vector..." << RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	sp.addNumbers(vec.begin(), vec.end());
	std::cout << CYAN << "\nAdding range from list..." << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(50);
	lst.push_back(150);
	lst.push_back(250);
	sp.addNumbers(lst.begin(), lst.end());
	std::cout << "Current size: " << sp.size() << "/" << sp.capacity() << "\n";
	std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
	std::cout << "Longest span: " << sp.longestSpan() << "\n";
}

void	testLargeDataset(void)
{
	const unsigned int	N = 100000;

	print_header("TEST 4 - LARGE DATASET (100K ELEMENTS)");
	Span sp(N);
	std::vector<int> numbers;
	std::srand(std::time(0));
	for (unsigned int i = 0; i < N; ++i)
	{
		numbers.push_back(std::rand() % (N * 10));
	}
	std::cout << CYAN << "Adding " << N << " random numbers..." << RESET << std::endl;
	sp.addNumbers(numbers.begin(), numbers.end());
	std::cout << "Calculating spans..." << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
	std::cout << "Longest span: " << sp.longestSpan() << "\n";
}

void	testEdgeCases(void)
{
	print_header("TEST 5 - EDGE CASE TESTS");
	std::cout << CYAN << "Testing with minimum integer values..." << RESET << std::endl;
	Span sp1(3);
	sp1.addNumber(std::numeric_limits<int>::min());
	sp1.addNumber(0);
	sp1.addNumber(std::numeric_limits<int>::max());
	std::cout << "Longest span: " << sp1.longestSpan() << " (should be max int)\n";
	std::cout << CYAN << "\nTesting with duplicate values..." << RESET << std::endl;
	Span sp2(5);
	sp2.addNumber(5);
	sp2.addNumber(5);
	sp2.addNumber(5);
	sp2.addNumber(10);
	sp2.addNumber(10);
	std::cout << "Shortest span: " << sp2.shortestSpan() << " (should be 0)\n";
	std::cout << "Longest span: " << sp2.longestSpan() << " (should be 5)\n";
}

int	main(void)
{
	testBasicOperations();
	testExceptions();
	testRangeInsertion();
	testLargeDataset();
	testEdgeCases();
	std::cout << MAGENTA << "\n━━━━━━━━━━ TESTS COMPLETED ━━━━━━━━━━\n" << RESET;
	return (0);
}
