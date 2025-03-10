/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:01:47 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/05 00:14:03 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static float	ft_pow(float base, int power)
{
	float	result;

	if (power == 0)
		return (1);
	if (power < 0)
	{
		base = 1 / base;
		power *= -1;
	}
	result = base;
	while (--power)
		result *= base;
	return (result);
}
/***
 *       ___             _               _
 *      / __|___ _ _  __| |_ _ _ _  _ __| |_ ___ _ _ ___
 *     | (__/ _ \ ' \(_-<  _| '_| || / _|  _/ _ \ '_(_-<
 *      \___\___/_||_/__/\__|_|  \_,_\__|\__\___/_| /__/
 *
 */
Fixed::Fixed(void) : _fixedPointValue(0)
{
	//std::cout << BOLD << "◎ Fixed object created with default constructor" << RESET << std::endl;
}

Fixed::Fixed(const int fixedPointValue) : _fixedPointValue(fixedPointValue
	* pow(2, this->_fractionalBits))
{
	//std::cout << BOLD << "◎ Fixed object created with int constructor" << RESET << std::endl;
}

Fixed::Fixed(const float fixedPointValue) : _fixedPointValue(fixedPointValue
	* pow(2, this->_fractionalBits))
{
	//std::cout << BOLD << "◎ Fixed object created with float constructor" << RESET << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << WARNING << "◎ Fixed object destroyed" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << BOLD << "◎ Fixed object created with copy constructor" << RESET << std::endl;
	*this = other;
}
/*** ___     _
 *  / _ \ __| |_ _ _ ___ __ _ _ __
 * | (_) (_-<  _| '_/ -_) _` | '  \
 *  \___//__/\__|_| \___\__,_|_|_|_|
 */

std::ostream &operator<<(std::ostream &str, const Fixed &fixed)
{
	return (str << fixed.toFloat());
}

/***___          _       ___                     _
 * | _ ) __ _ __(_)__   / _ \ _ __  ___ _ _ __ _| |_ ___ _ _ ___
 * | _ \/ _` (_-< / _| | (_) | '_ \/ -_) '_/ _` |  _/ _ \ '_(_-<
 * |___/\__,_/__/_\__|  \___/| .__/\___|_| \__,_|\__\___/_| /__/
 *                           |_|
 */

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << SUCCESS << "◎ Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const &copy) const
{
	Fixed result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed Fixed::operator-(Fixed const &copy) const
{
	Fixed result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed Fixed::operator*(Fixed const &copy) const
{
	Fixed result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed Fixed::operator/(Fixed const &copy) const
{
	Fixed result(this->toFloat() / copy.toFloat());
	return (result);
}

bool Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

/*** ___  _   _               ___                     _
 *  / _ \| |_| |_  ___ _ _   / _ \ _ __  ___ _ _ __ _| |_ ___ _ _ ___
 * | (_) |  _| ' \/ -_) '_| | (_) | '_ \/ -_) '_/ _` |  _/ _ \ '_(_-<
 *  \___/ \__|_||_\___|_|    \___/| .__/\___|_| \__,_|\__\___/_| /__/
 *                                |_|
 */

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator--(int value)
{
	Fixed	tmp;

	tmp = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (tmp);
}

Fixed Fixed::operator++(int value)
{
	Fixed	tmp;

	tmp = *this;
	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (tmp);
}

/***  __  __ _        __       __  __
 *   |  \/  (_)_ _   / _|___  |  \/  |__ ___ __
 *   | |\/| | | ' \  > _|_ _| | |\/| / _` \ \ /
 *   |_|  |_|_|_||_| \_____|  |_|  |_\__,_/_\_\
 */

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

/***  ___     _   _                __       ___      _   _
 *   / __|___| |_| |_ ___ _ _ ___ / _|___  / __| ___| |_| |_ ___ _ _ ___
 *  | (_ / -_)  _|  _/ -_) '_(_-< > _|_ _| \__ \/ -_)  _|  _/ -_) '_(_-<
 *   \___\___|\__|\__\___|_| /__/ \_____|  |___/\___|\__|\__\___|_| /__/
 */

int Fixed::getRawBits(void) const
{
	//std::cout << INFO << "◎ getRawBits member function called" << RESET << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << INFO << "◎ setRawBits member function called" << RESET << std::endl;
	this->_fixedPointValue = raw;
}

/*** ___                        _
 *  / __|___ _ ___ _____ _ _ __(_)___ _ _  ___
 * | (__/ _ \ ' \ V / -_) '_(_-< / _ \ ' \(_-<
 *  \___\___/_||_\_/\___|_| /__/_\___/_||_/__/
 */
float Fixed::toFloat(void) const
{
	return (this->_fixedPointValue * ft_pow(2, -this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue * pow(2, -this->_fractionalBits));
}
