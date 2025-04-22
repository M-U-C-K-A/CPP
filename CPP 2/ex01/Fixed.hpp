/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:01:52 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 20:17:42 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"

#define ERROR "\033[1;31m"
#define WARNING "\033[1;33m"
#define DEBUG "\033[1;35m"
#define SUCCESS "\033[1;32m"
#define INFO "\033[1;36m"

class Fixed
{
  public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed	&operator=(Fixed const &other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

  private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &str, const Fixed &fixed);
