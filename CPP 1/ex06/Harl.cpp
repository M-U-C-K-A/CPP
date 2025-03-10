/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:49:08 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/04 16:44:24 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << SPAWN << "A wild Harl has appeared!" << DEFAULT << std::endl;
}

Harl::~Harl(void)
{
	std::cout << DESTROY << "Wild Harl flew away!" << DEFAULT << std::endl;
}

void Harl::debug(void)
{
	std::cout << DEBUG << "[DEBUG]" << DEFAULT;
	std::cout << "\tI love having extra bacon for my" << std::endl;
	std::cout << "\t\t7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << INFO << "[INFO]" << DEFAULT;
	std::cout << "\tI cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "\t\tYou don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << WARNING << "[WARNING]" << DEFAULT;
	std::cout << "\tI think I deserve to have some extra bacon for free. " << std::endl;
	std::cout << "\t\tI've been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << ERROR << "[ERROR]" << DEFAULT;
	std::cout << "\tThis is unacceptable," << std::endl;
	std::cout << "\t\tI want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	bool	level_found;

	void (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	level_found = false;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			level_found = true;
		if (level_found)
			(this->*ptr_complain[i])();
	}
}
