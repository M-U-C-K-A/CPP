/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:44:40 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/27 23:28:38 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void	announce(void) const;
	void	setName(std::string name);
};

Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N, std::string name);
void	randomChump(std::string name);
