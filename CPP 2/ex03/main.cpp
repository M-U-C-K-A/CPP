/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:01:36 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/05 00:27:10 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int	main(void) {
	std::cout << std::boolalpha

		<< RESET << "◎ a(0, 0), b(0, 5), c(5, 0), point(1, 1): " << BOLD
		<< ::bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 1)) << std::endl

		<< RESET << "◎ a(0, 0), b(0, 5), c(5, 0), point(0, 5): " << BOLD
		<< ::bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5)) << std::endl

		<< RESET << "◎ a(0, 0), b(0, 5), c(5, 0), point(0, 3): " << BOLD
		<< ::bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl

		<< RESET << "◎ a(0, 0), b(0, 5), c(5, 0), point(0, 0): " << BOLD
		<< ::bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl

		<< RESET << "◎ a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): " << BOLD
		<< ::bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl

		<< RESET << "◎ a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): " << BOLD
		<< ::bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl

		<< RESET << "◎ a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): " << BOLD
		<< ::bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl;
}

