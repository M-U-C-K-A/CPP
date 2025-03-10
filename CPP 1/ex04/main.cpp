/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:35:25 by hdelacou          #+#    #+#             */
/*   Updated: 2025/03/03 23:43:39 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open input file: " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream outputFile(argv[2]);
	if (!outputFile.is_open())
	{
		std::cerr << "Failed to open output file: " << argv[2] << std::endl;
		return (EXIT_FAILURE);
	}
	std::string line;
	while (std::getline(inputFile, line))
		outputFile << line << std::endl;
	inputFile.close();
	outputFile.close();
	return (EXIT_SUCCESS);
}
