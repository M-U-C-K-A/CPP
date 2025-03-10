/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:32:45 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/05 17:42:09 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define RESET "\033[0m"
#define BOLD "\033[0;1m"
#define DIM "\033[2m"

#define DAMMAGE "\033[1;31m"
#define ENERGY "\033[1;33m"
#define HEALTH "\033[1;32m"
#define DEBUG "\033[1;35m"
#define INFO "\033[1;36m"

class ClapTrap
{
  public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(ClapTrap const &src);
	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};
