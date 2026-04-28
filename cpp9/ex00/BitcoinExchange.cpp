#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
	loadDatabase(databaseFile);
}

std::string BitcoinExchange::trim(const std::string& str) const {
	size_t first = str.find_first_not_of(" \t");
	if (std::string::npos == first) return "";
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file");

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue; // Skip header line
		}

		size_t pos = line.find(',');
		if (pos == std::string::npos) continue;

		std::string date = trim(line.substr(0, pos));
		std::string valueStr = trim(line.substr(pos + 1));

		float value = atof(valueStr.c_str());
		time_t timestamp = dateToTimestamp(date);
		_exchangeRates[timestamp] = value;
	}
}

time_t BitcoinExchange::dateToTimestamp(const std::string& date) const {
	struct tm tm;
	memset(&tm, 0, sizeof(tm));
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
		throw std::runtime_error("Error: bad date format => " + date);
	return mktime(&tm);
}


std::string BitcoinExchange::timestampToDate(time_t timestamp) const {
	char buffer[11];
	struct tm* tm = localtime(&timestamp);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm);
	return std::string(buffer);
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
	time_t target = dateToTimestamp(date);
	if (_exchangeRates.empty())
		throw std::runtime_error("Error: database is empty");

	std::map<time_t, float>::const_iterator it = _exchangeRates.lower_bound(target);

	if (it == _exchangeRates.begin() && it->first > target)
		throw std::runtime_error("Error: date is before earliest database entry");
	if (it != _exchangeRates.end() && it->first == target)
		return it->second;
	if (it == _exchangeRates.begin())
		return it->second;
	return (--it)->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	struct tm tm;
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
		return false;
	char buf[11];
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);
	return date == buf;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
	char* end;
	value = strtof(valueStr.c_str(), &end);

	if (*end != '\0' || end == valueStr.c_str())
		return false;
	if (value < 0) {
		std::cout << "Error: not a positive number" << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) {
	std::ifstream file(inputFile.c_str());
	if (!file.is_open()) throw std::runtime_error("Error: could not open input file");

	std::string line;
	while (std::getline(file, line)) {
		size_t delim = line.find('|');
		if (delim == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, delim));
		std::string valueStr = trim(line.substr(delim + 1));

		if (!isValidDate(date)) {
			std::cout << "Error: bad date format => " << date << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value)) continue;

		try {
			float rate = getExchangeRate(date);
			std::cout << date << " => " << value << " = " << std::fixed
					  << std::setprecision(2) << (value * rate) << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
