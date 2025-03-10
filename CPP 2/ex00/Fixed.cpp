/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:01:47 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/04 17:16:37 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << BOLD << "◎ Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << DEBUG << "◎ Copy constructor called" << RESET << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << WARNING << "◎ Destructor called" << RESET << std::endl;
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
	std::cout << "◎ setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
