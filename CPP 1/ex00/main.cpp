/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:51:48 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/27 22:03:12 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("buckethead Zombie ");
	randomChump("basic Zombie ");
	delete zombie;
	return (EXIT_SUCCESS);
}
