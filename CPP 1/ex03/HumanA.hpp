/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:34:41 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/03 21:53:27 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
  private:
	std::string _name;
	Weapon &_weapon;

  public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void attack(void);
	void setWeapon(Weapon &weapon);
};
