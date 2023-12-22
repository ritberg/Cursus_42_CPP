/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:46:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/12/16 13:47:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange&  BitcoinExchange::operator=(BitcoinExchange const & other)
{
    if (this != &other)
    {
        this->_rates = other._rates;
    }
    return (*this);
}

void BitcoinExchange::checkInput(const std::string& input) const
{
    try
    {
        std::ifstream ifs;

        if (input.empty())
            throw std::invalid_argument("empty input.");
        ifs.open (input, std::ifstream::in);
        if (!ifs.is_open() || ifs.fail())
            throw std::runtime_error("no such file or permission denied.");
        if (ifs.peek() == EOF)
            throw std::runtime_error("empty file.");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


double BitcoinExchange::_valueConverter(std::string valueStr) const
{
	double value = std::atof(valueStr.c_str());
	if (value < 0)
        throw std::invalid_argument(valueStr + " not a positive value");
	else if (value > std::numeric_limits<int>::max())
        throw std::invalid_argument(valueStr + " too large");  
	return (value);
}


void BitcoinExchange::processInput(const std::string& file)
{
    std::ifstream ifs(file);
    std::string line;
    try
    {
        std::getline(ifs, line);
        if (line != "date | value") // Skip the first line
            throw std::invalid_argument("Error: Bad file format");

        while (std::getline(ifs, line))
        {
            try
            {
                std::string date = line.substr(0, 10);
                if (date.empty())
                    throw std::invalid_argument("substraction of the date failed");

                double value = _valueConverter(line.substr(13));
                if (!value)
                    throw std::invalid_argument("conversion failed");

                size_t pos = line.find(" | ");    // Find the position of the first occurrence of " | "

                if (pos != std::string::npos)
                {
                    std::string valueStr = line.substr(pos + 3);
                    std::istringstream valueIss(valueStr);
                    if (valueIss >> value)
                        this->_rates[date] = value;
                    else
                        throw std::invalid_argument("converting value to double failed");
                }
                else
                {
                    std::cout << "here" << std::endl;
                    throw std::invalid_argument("bad file format");
                }

                double exchangeRate = _findClosestExchangeRate(date);
                if (value > 0)
                {
                    double result = value * exchangeRate;
                    std::cout << date << " => " << value << " = " << std::setprecision(2) << result << std::endl;
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }

        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error reading file: " << e.what() << std::endl;
    }

    ifs.close();
}

void extractDataFromCSV(const std::string& filePath, std::map<std::string, double>& dataMap) {
    std::ifstream file(filePath.c_str());

    if (!file)
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        // Use stringstream to split the line using ',' as a delimiter
        std::istringstream ss(line);
        std::string key, valueStr;

        // Read the key (string before the comma)
        if (std::getline(ss, key, ',')) {
            // Read the value (number after the comma)
            if (std::getline(ss, valueStr, ',')) {
                // Attempt to convert the value to a double
                double value;
                std::istringstream(valueStr) >> value;

                // Check if the conversion was successful
                if (!ss.fail()) {
                    // Insert into the map
                    dataMap[key] = value;
                } else {
                    std::cerr << "Skipping line - Unable to convert '" << valueStr << "' to a double." << std::endl;
                }
            } else {
                std::cerr << "Skipping line - No value found after ','." << std::endl;
            }
        }
    }

    file.close();
}

double BitcoinExchange::_findClosestExchangeRate(const std::string& date) const
{
    std::map<std::string, double> rates;
    extractDataFromCSV("data.csv", rates);

    std::map<std::string, double>::const_iterator it = rates.lower_bound(date);
    if (it != rates.begin())
    {
        if (it->first != date)
            --it;
        return it->second;
    }
    return (it->second);
}