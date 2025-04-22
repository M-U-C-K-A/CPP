/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:20:53 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/09 21:47:20 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
	std::cout << BOLD << MAGENTA << "\n========== 🏰 MATERIA SOURCE SETUP 🏰 ==========" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << BOLD << MAGENTA << "\n========== 🧙 CHARACTER CREATION 🧙 ==========" << RESET << std::endl;
	ICharacter* me = new Character("Hero");
	ICharacter* bob = new Character("Bob the Target");

	std::cout << BOLD << MAGENTA << "\n========== 🎒 EQUIPMENT TEST 🎒 ==========" << RESET << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << BOLD << MAGENTA << "\n========== ⚔️ COMBAT TEST ⚔️ ==========" << RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << BOLD << MAGENTA << "\n========== 🧹 CLEANUP 🧹 ==========" << RESET << std::endl;
	delete bob;
	delete me;
	delete src;

	std::cout << BOLD << GREEN << "\n🏁 Program completed successfully! 🏁" << RESET << std::endl;
	return 0;
}
