/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:33:21 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/03 21:41:38 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon(std::string type);
	~Weapon(void);
	const std::string& getType(void);	//review this line
	void setType(std::string type);
};
