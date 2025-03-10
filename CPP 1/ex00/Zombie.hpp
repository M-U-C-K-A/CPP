/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:44:40 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/18 18:59:51 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string s);
		~Zombie();
		void	announce(void)const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
