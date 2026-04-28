/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:43:12 by hdelacou          #+#    #+#             */
/*   Updated: 2026/04/28 15:33:51 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op) {
	if (_stack.size() < 2) {
		throw std::runtime_error("Error");
	}

	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();

	if (op == '+') {
		_stack.push(a + b);
	} else if (op == '-') {
		_stack.push(a - b);
	} else if (op == '*') {
		_stack.push(a * b);
	} else if (op == '/') {
		if (b == 0) {
			throw std::runtime_error("Error");
		}
		_stack.push(a / b);
	}
}

void RPN::calculate(const std::string& expression) {
	for (size_t i = 0; i < expression.length(); ++i) {
		char c = expression[i];

		if (c == ' ') {
			continue;
		} else if (std::isdigit(c)) {
			_stack.push(c - '0');
		} else if (isOperator(c)) {
			performOperation(c);
		} else {
			throw std::runtime_error("Error");
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error");
	}

	std::cout << _stack.top() << std::endl;
}
