/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:10:28 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/05 00:10:33 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::~Point() {}

Point::Point(Point const &other) {
	*this = other;
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y) {}

Point&	Point::operator=(Point const &other) {
	(void)other;
	return *this;
}

Fixed const &Point::getX(void) const {
	return _x;
}

Fixed const &Point::getY(void) const {
	return _y;
}
