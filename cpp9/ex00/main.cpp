/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:05:56 by hdelacou          #+#    #+#             */
/*   Updated: 2025/07/01 18:19:57 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <assert.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange("data.csv");

    try {
        assert(exchange.dateToTimestamp("2017-01-01") == 1483228800);
        assert(exchange.dateToTimestamp("2018-01-01") == 1514764800);
        assert(exchange.dateToTimestamp("2019-01-01") == 1546300800);

        exchange.processInputFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

