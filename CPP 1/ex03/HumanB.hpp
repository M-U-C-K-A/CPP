/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:36:32 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/03 22:06:20 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
  private:
	std::string _name;
	Weapon *_weapon;

  public:
	HumanB(std::string name);
	~HumanB(void);
	void attack(void);
	void setWeapon(Weapon &weapon);
};
