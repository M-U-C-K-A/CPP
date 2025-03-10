/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:01:47 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/04 23:54:27 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << BOLD << "◎ Fixed object created with default constructor" << RESET << std::endl;
}

Fixed::Fixed(const int fixedPointValue) : _fixedPointValue(fixedPointValue * pow(2, this->_fractionalBits))
{
	std::cout << BOLD << "◎ Fixed object created with int constructor" << RESET << std::endl;
}

Fixed::Fixed(const float fixedPointValue) : _fixedPointValue(fixedPointValue * pow(2, this->_fractionalBits))
{
	std::cout << BOLD << "◎ Fixed object created with float constructor" << RESET << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << WARNING << "◎ Fixed object destroyed" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << BOLD << "◎ Fixed object created with copy constructor" << RESET << std::endl;
	*this = other;
}

float Fixed::toFloat(void) const
{
	return (this->_fixedPointValue * pow(2, -this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue * pow(2, -this->_fractionalBits));
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << SUCCESS << "◎ Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << INFO << "◎ getRawBits member function called" << RESET << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << INFO << "◎ setRawBits member function called" << RESET << std::endl;
	this->_fixedPointValue = raw;
}

std::ostream &operator << (std::ostream &str, const Fixed &fixed)
{
	return (str << fixed.toFloat());
}

