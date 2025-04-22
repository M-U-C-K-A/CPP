/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:05:55 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/12 00:49:33 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	ScavTrap(const ScavTrap &scavTrap);
	ScavTrap &operator=(const ScavTrap &scavTrap);
	~ScavTrap();
	ScavTrap(std::string name);
	void attack(const std::string &target);
	void guardGate(void);
};
