/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:02:24 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/05 00:05:11 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point(void);
		~Point(void);
		Point(const Point &point);
		Point(Fixed const x, Fixed const y);
		Point &operator=(const Point &point);
		Fixed const &getX(void) const;
		Fixed const &getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
