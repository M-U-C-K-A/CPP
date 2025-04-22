/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:31:27 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/12 00:01:24 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{

	std::cout << RESET << DIM << "---- CONSTRUCTORS ----" << RESET << std::endl;
	ClapTrap carapuce("Carapuce");
	ScavTrap bulbizar("Bulbizar");
	ScavTrap pikachu;
	ScavTrap bulbiclone = bulbizar;

	std::cout << RESET << DIM << std::endl << "---- VALID ACTIONS ----" << RESET << std::endl;
	carapuce.attack("Bulbizar");
	bulbizar.attack("Carapuce");
	bulbizar.takeDamage(2);
	bulbizar.beRepaired(1);
	bulbizar.guardGate();

	std::cout << RESET << DIM << std::endl << "---- INVALID ACTIONS ----" << RESET << std::endl;
	bulbizar.takeDamage(100);
	bulbizar.attack("Carapuce");
	bulbizar.takeDamage(2);
	bulbizar.beRepaired(2);
	bulbizar.guardGate();

	for (int i = 0; i < 12; i++)
		bulbiclone.attack("Carapuce");

	std::cout << RESET << DIM << std::endl << "---- DESTRUCTORS ----" << RESET << std::endl;
	return (0);
}
