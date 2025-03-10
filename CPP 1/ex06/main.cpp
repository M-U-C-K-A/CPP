/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:55:25 by aperez-b          #+#    #+#             */
/*   Updated: 2025/03/04 16:54:09 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	harl_switch(char *argv, Harl &harl)
{
	int value;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (levels[i] == argv)
			value = i;

	switch (value)
	{
		case 0:
			harl.complain("DEBUG");
			break ;
		case 1:
			harl.complain("INFO");
			break ;
		case 2:
			harl.complain("WARNING");
			break ;
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << ERROR << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		std::cout << ERROR << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl_switch(argv[1], harl);
	return (0);
}

