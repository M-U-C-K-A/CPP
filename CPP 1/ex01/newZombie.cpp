/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:48:48 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/18 18:50:08 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *buckethead_zombie = new Zombie(name);
	buckethead_zombie->announce();
	return (buckethead_zombie);
}
