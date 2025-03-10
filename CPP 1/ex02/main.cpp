/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:57:19 by hdelacou          #+#    #+#             */
/*   Updated: 2025/02/28 00:11:56 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;
	std::cout << "\033[94;1m◎ Memory\033[0;1m address of the string variable: ◦ \033[94m" << &brain << std::endl;
	std::cout << "\033[94m◎ Memory\033[0;1m address held by stringPTR:◦ ◦ ◦ ◦ \033[94m" << stringPTR << std::endl;
	std::cout << "\033[94m◎ Memory\033[0;1m address held by stringREF:◦ ◦ ◦ ◦ \033[94m" << &stringREF << std::endl;
	std::cout << "\n\033[90m◎ Value\033[0;1m of the string variable:  ◦ ◦ ◦ ◦ ◦ \033[90m" << brain << std::endl;
	std::cout << "\033[90m◎ Value\033[0;1m pointed to by stringPTR: ◦ ◦ ◦ ◦ ◦ \033[90m" << *stringPTR << std::endl;
	std::cout << "\033[90m◎ Value\033[0;1m pointed to by stringREF: ◦ ◦ ◦ ◦ ◦ \033[90m" << stringREF << std::endl;

	return (0);
}

