/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:20:21 by hdelacou          #+#    #+#             */
/*   Updated: 2025/07/01 18:25:14 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <ctime>

#define RESET "\033[0m"
#define BOLD "\033[0;1m"
#define DIM "\033[2m"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& databaseFile);
    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& inputFile);

private:
    std::map<time_t, float> _exchangeRates;

    time_t dateToTimestamp(const std::string& date) const;
    std::string timestampToDate(time_t timestamp) const;
    float getExchangeRate(const std::string& date) const;

    std::string trim(const std::string& str) const;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
};
