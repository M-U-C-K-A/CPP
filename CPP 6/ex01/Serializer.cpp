/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:13:35 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/17 21:23:11 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}
Serializer::Serializer(const Serializer &)
{
}
Serializer &Serializer::operator=(const Serializer &)
{
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	std::cout << YELLOW << "Sérialisation de " << BOLD << ptr << RESET << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data	*result;

	result = reinterpret_cast<Data *>(raw);
	std::cout << YELLOW << "Désérialisation vers " << BOLD << result << RESET << std::endl;
	return (result);
}
