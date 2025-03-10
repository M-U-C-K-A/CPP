/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:49:16 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/04 16:44:48 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define DEFAULT	"\033[0m"
#define SPAWN	"\033[2;32m"
#define DESTROY	"\033[2;36m"

#define ERROR	"\033[1;31m◎ "
#define WARNING	"\033[1;33m◎ "
#define DEBUG	"\033[1;35m◎ "
#define INFO	"\033[1;37m◎ "

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);
};
