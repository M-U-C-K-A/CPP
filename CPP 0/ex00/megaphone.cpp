/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:33:55 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/10 15:20:54 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <iostream>

void	pntToupper(char &c)
{
	c = std::toupper(c);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			for (int j = 0; argv[i][j]; ++j)
				std::cout << (char)std::toupper(argv[i][j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}
