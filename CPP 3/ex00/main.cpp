/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:31:27 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/05 17:46:40 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << RESET << DIM << "---- CONSTRUCTORS ----" << RESET << std::endl;
	ClapTrap bulbizar("Bulbizar");
	ClapTrap salameche("Salamèche");
	ClapTrap carapuce("Carapuce");
	ClapTrap mew("Mew");
	ClapTrap pikachu;
	ClapTrap mewTwo(mew);
	ClapTrap mewThree = carapuce;

	std::cout << RESET << DIM << std::endl << "---- VALID ACTIONS ----" << RESET << std::endl;
	bulbizar.attack("Salamèche");
	salameche.takeDamage(2);
	carapuce.beRepaired(1);
	carapuce.beRepaired(2);
	carapuce.beRepaired(1);
	carapuce.beRepaired(4);

	std::cout << RESET << DIM << std::endl << "---- INVALID ACTIONS ----" << RESET << std::endl;
	bulbizar.takeDamage(10);
	bulbizar.beRepaired(10);
	salameche.takeDamage(20);
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");
	salameche.attack("Bulbizar");

	std::cout << RESET << DIM << std::endl << "---- DESTRUCTORS ----" << RESET << std::endl;
	return (0);
}
