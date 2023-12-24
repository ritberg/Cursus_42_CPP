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
    std::ifstream ifs;

    if (input.empty())
        throw std::invalid_argument("Error: empty input.");
    ifs.open (input, std::ifstream::in);
    if (!ifs.is_open() || ifs.fail())
        throw std::runtime_error("Error: no such file or permission denied.");
    if (ifs.peek() == EOF)
        throw std::runtime_error("Error: empty file.");
}


double BitcoinExchange::_valueConverter(const std::string& valueStr) const
{
    if (valueStr.empty())
        throw std::invalid_argument("empty value");
	double value = std::atof(valueStr.c_str());
	if (value < 0)
        throw std::invalid_argument("not a positive value");
    else if (value > std::numeric_limits<int>::max())
        throw std::invalid_argument("too large a number");
    else if	(value > 1000)
        throw std::invalid_argument("value is bigger than 1000");
	return (value);
}

bool BitcoinExchange::_checkDate(const std::string& date) const
{
    if (date.length() != 10)
        return (false);

    std::istringstream iss(date);  // Use std::istringstream to parse the date components
    char dash1, dash2;
    int year, month, day;

    if (!(iss >> year >> dash1 >> month >> dash2 >> day)) // Attempt to parse the date components
        return (false);

    return (dash1 == '-' && dash2 == '-' &&  // Check for correct formatting and valid ranges
            year >= 1900 && year <= 2023 &&
            month >= 1 && month <= 12 &&
            day >= 1 && day <= 31);
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
                size_t nullPos = line.find(' ');
                std::string date = line.substr(0, nullPos);
                if (_checkDate(date) == false)
                    throw std::invalid_argument("bad input => " + date);
                else
                {
                    if (line.size() <= 13)
                        throw std::invalid_argument("Error: Missing value in the input line");
                    double value = _valueConverter(line.substr(13));

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
                    double exchangeRate = _findClosestExchangeRate(date);
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
        std::cerr << e.what() << std::endl;
    }
    ifs.close();
}

void extractDataFromCSV(const std::string& filePath, std::map<std::string, double>& dataMap)
{
    std::ifstream file(filePath.c_str());

    if (!file)
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);  // Use stringstream to split the line using ',' as a delimiter
        std::string key, valueStr;

        if (std::getline(ss, key, ','))  // Read the key (string before the comma)
        {
            if (std::getline(ss, valueStr, ','))  // Read the value (number after the comma)
            {
                double value;                           // Attempt to convert the value to a double
                std::istringstream(valueStr) >> value;

                if (!ss.fail())
                    dataMap[key] = value;   // Insert into the map
                else 
                    std::cerr << "Skipping line - Unable to convert '" << valueStr << "' to a double." << std::endl;
            }
            else
                std::cerr << "Skipping line - No value found after ','." << std::endl;
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