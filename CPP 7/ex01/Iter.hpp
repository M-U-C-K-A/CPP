/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:23:05 by hdelacou          #+#    #+#             */
/*   Updated: 2025/04/19 19:34:52 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void iter(T *array, size_t length, void (*func)(T &))
{
	if (!array || !func)
	{
		std::cerr << "\033[1;31mError: Null pointer passed to iter\033[0m" << std::endl;
		return ;
	}
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}
