/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:51:48 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/27 23:49:40 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("buckethead Zombie");
	randomChump("basic Zombie");
	delete zombie1;

	int N = 5;
	Zombie *horde = zombieHorde(N, "horde Zombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;

	Zombie *zombie2 = newZombie("buckethead Zombie");
	randomChump("basic Zombie");
	delete zombie2;

	return (EXIT_SUCCESS);
}

