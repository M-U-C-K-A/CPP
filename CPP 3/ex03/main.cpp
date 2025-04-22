/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:31:27 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/08 21:29:21 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << RESET << DIM << "---- CONSTRUCTORS ----" << RESET << std::endl;
	ClapTrap carapuce("Carapuce");
	ScavTrap bulbizar("Bulbizar");
	ScavTrap bulbiclone = bulbizar;
	FragTrap Miradar("Miradar");
	FragTrap pikachu;
	DiamondTrap diamond("Diamond");

	std::cout << RESET << DIM << std::endl << "---- VALID ACTIONS ----" << RESET << std::endl;
	carapuce.attack("Bulbizar");
	bulbizar.attack("Carapuce");
	bulbizar.takeDamage(2);
	bulbizar.beRepaired(1);
	bulbizar.guardGate();
	Miradar.highFivesGuys();
	Miradar.highFivesGuys();
	Miradar.highFivesGuys();

	std::cout << RESET << DIM << std::endl << "---- INVALID ACTIONS ----" << RESET << std::endl;
	bulbizar.takeDamage(100);
	bulbizar.attack("Carapuce");
	bulbizar.takeDamage(2);
	bulbizar.beRepaired(2);
	bulbizar.guardGate();

	for (int i = 0; i < 5; i++)
		bulbiclone.attack("Carapuce");

	std::cout << RESET << DIM << std::endl << "---- DIAMOND TRAP ----" << RESET << std::endl;
	diamond.attack("Carapuce");
	diamond.takeDamage(2);
	diamond.beRepaired(1);
	diamond.guardGate();
	diamond.whoAmI();
	diamond.highFivesGuys();
	diamond.whoAmI();

	std::cout << RESET << DIM << std::endl << "---- DESTRUCTORS ----" << RESET << std::endl;
	return (0);
}

